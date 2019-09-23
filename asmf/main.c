/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	set the name of the ouput file
** @param	char	*s			- string, name of the input file
** @return						- void
*/

static char	*set_output_name(char *s)
{
	char	*name;
	char	**tmp;

	if (ft_strlen(s) < 1)
		exit(!!ft_printf("ERROR: output file name not defined\n"));
	tmp = ft_strsplit(s, '.');
	if (ft_strlen(tmp[0]) > 0)
		name = ft_strjoin(tmp[0], ".cor");
	else
		name = ft_strdup(".cor");
	if (ft_strlen(name) < 1)
		exit(!!ft_printf("ERROR: output file name couldn't be set\n"));
	free_str_arr(NULL, &tmp, 0);
	return (name);
}

/*
** @desc	switch between label getter and instruction getter
** @param	t_data	*data		- pointer to data structure
** @param	char	*s			- clean string w/o starting/trailing whitespaces
** @return	int		res			- offset of instruction/label from the start of
**									champion executable code
*/

int			get_labels_instructions(t_data *data, char *s)
{
	char		**tmp;
	char		*space_string;
	int			i;
	int			res;

	space_string = add_spaces(&s);
	tmp = ft_strsplit_whitespace(space_string);
	free_str_arr(&space_string, NULL, 1);
	i = 0;
	while (tmp[i])
		i++;
	res = 0;
	if (is_label(tmp[0]))
		res = get_label(data, tmp, i);
	else if (is_instruction(tmp[0]) != 0)
		res = get_instruction(data, tmp, is_instruction(tmp[0]), i);
	else if (s[0] != '#')
		exit(!!ft_printf("ERROR: couldn't read line %d %s\n", data->line_qty));
	free_str_arr(NULL, &tmp, 0);
	return (res);
}

/*
** @desc	switch between name/comment getter and label/instruction getter
** @param	t_data	*data		- pointer to data structure
** @param	char	*tmp		- clean string w/o starting/trailing whitespaces
** @return						- void
*/

static void	choose_fun(t_data *data, char *tmp)
{
	char	**arr;

	if (ft_strchr(tmp, COMMENT_CHAR))
		arr = ft_strsplit(tmp, COMMENT_CHAR);
	else
		arr = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (ft_strlen(tmp) > 0 && tmp[0] != COMMENT_CHAR
		&& tmp[0] != ALT_COMMENT_CHAR)
	{
		if (strncmp(arr[0], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
			get_name_comment(data, arr[0], 1);
		else if (strncmp(arr[0], COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
			get_name_comment(data, arr[0], 2);
		else
			get_labels_instructions(data, arr[0]);
	}
	free_str_arr(NULL, &arr, 0);
}

/*
** @desc	main conversion loop, iterates while smth. is read
** @param	t_data *data		- pointer to data structure
** @return						- void
*/

static void	conversion_loop(t_data *data)
{
	char		*s;

	while (get_clean_string(data, &s) > 0)
	{
		data->line_qty++;
		if (ft_strlen(s) > 0)
			choose_fun(data, s);
		free_str_arr(&s, NULL, 1);
	}
	free_str_arr(&s, NULL, 1);
}

/*
** @desc	get file names as arguments and send last argument to conversion
** @param	int argc			- amount of arguments
** @param	char **s argv		- array of string arguments
** @return						- 0
*/

int			main(int argc, char **argv)
{
	char	*file_name;
	t_data	*data;

	if (argc < 2)
		exit(!!ft_printf("usage: ./asm file_name\n"));
	data = (t_data*)ft_memalloc(sizeof(t_data));
	get_data(data);
	data->fd_r = open(argv[argc - 1], O_RDONLY);
	if (data->fd_r < 3)
		exit(!!ft_printf("ERROR: file %s couldn't be read\n", argv[argc - 1]));
	conversion_loop(data);
	check(data);
	file_name = set_output_name(argv[argc - 1]);
	data->fd_w = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data->fd_w < 3)
		exit(!!ft_printf("ERROR: file %s not created\n", file_name));
	write_data(data);
	ft_printf("Writing output program to %s\n", file_name);
	close(data->fd_w);
	close(data->fd_r);
	return (0);
}
