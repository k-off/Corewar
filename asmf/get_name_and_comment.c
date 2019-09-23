/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_name_and_comment.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	add a newline character to the end of each line of name or comment
** @param	char **s			- pointer to string
** @return						- void
*/

static void	add_newline(char **s)
{
	char	*tmp;

	tmp = ft_strjoin(*s, "\n");
	free_str_arr(s, NULL, 1);
	*s = tmp;
}

/*
** @desc	check length of .name and .comment, exit if exceed max. limit
** @param	char *s				- name or comment string
** @param	int flag			- 1 for name, 2 for comment
** @return						- void
*/

static void	check_lengths(char *s, int flag)
{
	if (flag == 1 && ft_strlen(s) > PROG_NAME_LENGTH)
		exit(!!ft_printf("ERROR: .name too long (max %d)\n", PROG_NAME_LENGTH));
	if (flag == 0 && ft_strlen(s) > COMMENT_LENGTH)
		exit(!!ft_printf("ERROR: .coment too long (max %d)\n", COMMENT_LENGTH));
}

/*
** @desc	check quotation marks for .name and .comment
** @param	t_data *data		- pointer to all data
** @param	char *s				- name or comment string
** @return						- 1 if both quotes are on the same line
** @return						- 0 if one quote is on the same line
** @return						- -1 if no quotes
*/

static int	on_same_line(char *s)
{
	int		i;
	int		count_quotes;

	i = (int)ft_strlen(s);
	count_quotes = 0;
	while (i > 0 && count_quotes < 2)
	{
		i--;
		if (s[i] == '"')
			count_quotes++;
	}
	if (count_quotes > 1)
		return (1);
	else if (count_quotes > 0)
		return (0);
	else
		return (-1);
}

/*
** @desc	gets the entire name or comment if it is on multiple lines
** @param	t_data *data		- pointer to all data
** @param	char *s				- name or comment string
** @param	int flag			- 1 for name, 2 for comment
** @return						- void
*/

static void	get_multiple_lines(t_data *data, char **s, int flag)
{
	char	*join_tmp;
	char	*read_tmp;
	char	*quote_pos;

	while (get_next_line(data->fd_r, &read_tmp))
	{
		quote_pos = ft_strchr(read_tmp, '"');
		if (quote_pos != NULL)
			quote_pos[0] = 0;
		data->line_qty++;
		if (ft_strstr(read_tmp, NAME_CMD_STRING)
			|| ft_strstr(read_tmp, COMMENT_CMD_STRING))
			exit(!!ft_printf("ERROR: no quote (lin %d)\n", data->line_qty - 1));
		join_tmp = ft_strjoin(*s, read_tmp);
		free_str_arr(s, NULL, 1);
		free_str_arr(&read_tmp, NULL, 1);
		*s = join_tmp;
		join_tmp = 0;
		check_lengths(*s, flag);
		if (quote_pos != NULL)
			break ;
		add_newline(s);
	}
}

/*
** @desc	gets name or comment and saves it into the data structure
** @param	t_data *data		- pointer to all data
** @param	char *s				- raw read line
** @param	int flag			- 1 for name, 2 for comment
** @return						- void
*/

void		get_name_comment(t_data *data, char *s, int flag)
{
	char	**tmp;
	int		one_line;

	tmp = ft_strsplit(s, '"');
	one_line = on_same_line(s);
	if (one_line == -1)
		exit(!!ft_printf("ERROR: no quotes (line %d)\n", data->line_qty));
	if (tmp[1])
		s = ft_strdup(tmp[1]);
	else
		s = ft_strdup("");
	if (one_line < 1)
		add_newline(&s);
	if (one_line < 1)
		get_multiple_lines(data, &s, flag);
	check_lengths(s, flag);
	if (flag == 1 && !data->name)
		data->name = s;
	if (flag == 2 && !data->comment)
		data->comment = s;
	free_str_arr(NULL, &tmp, 0);
}
