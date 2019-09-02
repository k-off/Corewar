/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	save pointer to the data structure
** @param	t_data *data		- pointer to the data structure to be saved
** @return	t_data *save_data	- saved pointer
*/

t_data		*get_data(t_data *data)
{
	static t_data *saved_data = 0;

	if (!saved_data)
		saved_data = data;
	return (saved_data);
}

/*
** @desc	check whether all argument characters are in allowed set
** @param	char *allowed		- set of allowed characters
** @param	char *arg			- checked argument
** @return	int					- 1: is allowed, 0: is not allowed
*/

int			only_allowed_chars(char *allowed, char *arg)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(arg);
	while (i < len)
	{
		if (!ft_strchr(allowed, arg[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
** @desc	free a string or an array of strings or both types
** @param	char **s			- pointer to string
** @param	char ***arr			- pointer to array of strings
** @param	int flag			- 1: free string, 0: free array, 2: free both
** @return						- void
*/

void		free_str_arr(char **s, char ***arr, int flag)
{
	int			i;

	if ((flag == 1 || flag == 2) && *s != 0)
	{
		free(*s);
		*s = 0;
	}
	if ((flag == 0 || flag == 2) && arr != 0 && *arr != 0)
	{
		i = 0;
		while (arr[0][i])
		{
			free(arr[0][i]);
			arr[0][i] = 0;
			i++;
		}
		free(*arr);
		*arr = 0;
	}
}

/*
** @desc	get a clean string w/o comments and w/o spaces at start and end
** @param	t_data *data		- pointer to data structure
** @param	char **arr			- pointer to string
** @return	int	res				- return 1 if read smth.(even if strlen == NULL)
*/

int			get_clean_string(t_data *data, char **dst)
{
	char		*s;
	char		*tmp;
	int			res;
	char		**arr;

	res = get_next_line(data->fd_r, &s);
	tmp = ft_strtrim(s);
	free_str_arr(&s, NULL, 1);
	if (tmp == NULL || ft_strlen(tmp) == 0)
	{
		*dst = ft_strdup("");
		free_str_arr(&tmp, NULL, 1);
		return (res);
	}
	arr = 0;
	if (tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
		*dst = ft_strdup("");
	else if (ft_strchr(tmp, COMMENT_CHAR))
		arr = ft_strsplit(tmp, COMMENT_CHAR);
	else
		arr = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (arr != 0 && ft_strlen(arr[0]) > 0)
		*dst = ft_strdup(arr[0]);
	free_str_arr(&tmp, &arr, 2);
	return (res);
}
