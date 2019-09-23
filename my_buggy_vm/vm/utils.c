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

#include "vm.h"

/*
 ** @desc	write into vm memory
 ** @param	t_data	*data		- pointer to data structure
 ** @param	int		pos			- position of the first byte to overwrite
 ** @param	int		size		- how many bytes to overwrite
 ** @return						- void
 */

void	write_memory(unsigned char *dst, unsigned char *src,
				int position,  unsigned total_length)
{
	int		cur_pos;
	int		i;

	i = 0;
	while (i < total_length)
	{
		cur_pos = (position + total_length - i - 1) % MEM_SIZE;
		dst[cur_pos] = src[i];
//		ft_printf("%8x\n", *((unsigned*)src));
		i++;
	}
}

/*
** @desc	read vm memory
** @param	t_data	*data		- pointer to data structure
** @param	int		pos			- position of the first byte to read
** @param	int		size		- how many bytes to read
** @return						- void
*/

int			read_memory(unsigned char *s, int start_pos, int size)
{
	int			i;
	unsigned	tmp;
	int			res;
	
	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp = tmp << 8;
		tmp |= s[(i + start_pos) % MEM_SIZE];
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
** @desc	convert binary string into an int
** @param	unsigned *char		- pointer to converted string
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
** @param	t_game *game		- pointer to the data structure to be saved
** @return	t_game *saved_game	- saved pointer
*/

t_game		*get_game(t_game *game)
{
	static t_game *saved_game = 0;

	if (!saved_game)
		saved_game = game;
	return (saved_game);
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

