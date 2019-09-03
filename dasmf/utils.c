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

#include "../includes/disassembler.h"

/*
** @desc	convert binary string into an int
** @param	t_data *data		- pointer to data structure
** @return						- void
*/

int			get_number(unsigned char *s, int size)
{
	int			i;
	unsigned	tmp;
	int			res;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp = tmp << 8;
		tmp |= s[i];
		i++;
	}
	if (size == 1)
		res = (char)tmp;
	else if (size == 2)
		res = (short)tmp;
	else
		res = (int)tmp;
	return (res);
}

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
