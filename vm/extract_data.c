/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 11:38:00 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/21 11:38:02 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Extract decimal value from 4 bytes.
** @desc 00 00 00 2a would be translated as 42.
** @param int byte_1 - starting byte of 4 bytes
** @param byte_1 is used to access specific byte
** @param from the arena or the memory where executables are placed.
** @return int as decimal value of 4 bytes
*/

/*
** int		extract_4_bytes(int byte_1)
** {
** 	int				dir_value;
** 	int				reversed;
** 	unsigned char	*arena;
** 	dir_value = 0;
** 	reversed = 0;
** 	arena = save_arena(NULL);
** 	dir_value = dir_value | arena[(byte_1 + 3) % MEM_SIZE];
** 	dir_value = dir_value << 8;
** 	dir_value = dir_value | arena[(byte_1 + 2) % MEM_SIZE];
** 	dir_value = dir_value << 8;
** 	dir_value = dir_value | arena[(byte_1 + 1) % MEM_SIZE];
** 	dir_value = dir_value << 8;
** 	dir_value = dir_value | arena[(byte_1) % MEM_SIZE];
** 	reversed = reversed | (dir_value & 0x000000FF);
** 	reversed = reversed << 24;
** 	reversed = reversed | ((dir_value & 0x0000FF00) << 8);
** 	reversed = reversed | ((dir_value & 0x00FF0000) >> 8);
** 	reversed = reversed | ((dir_value & 0xFF000000) >> 24);
** 	return (reversed);
** }
*/

int			extract_4_bytes(int byte_1)
{
	int				i;
	unsigned		tmp;
	int				res;
	unsigned char	*s;

	s = save_arena(NULL);
	i = 0;
	tmp = 0;
	while (i < 4)
	{
		tmp = tmp << 8;
		tmp |= s[byte_1 % 4096];
		i++;
		byte_1++;
	}
	res = (int)tmp;
	return (res);
}

/*
** int		extract_2_bytes(int byte_1)
** {
** 	int				dir_value;
** 	int				reversed;
** 	unsigned char	*arena;
** 	int				negative;
** 	dir_value = 0;
** 	reversed = 0;
** 	arena = save_arena(NULL);
** 	negative = 0;
** 	if (arena[(byte_1) % MEM_SIZE] > 127)// previously was byte_1 + 1
** 		negative = 1;
** 	dir_value = dir_value | arena[(byte_1 + 1) % MEM_SIZE];
** 	dir_value = dir_value << 8;
** 	dir_value = dir_value | arena[byte_1 % MEM_SIZE];
** 	reversed = reversed | (dir_value & 0x00FF);
** 	reversed = reversed << 8;
** 	reversed = reversed | ((dir_value & 0xFF00) >> 8);
** 	if (negative == 1)
** 	{
** 		reversed = reversed - 1;
** 		reversed = (reversed ^ 0xFFFF) * -1;
** 	}
** 	return (reversed);
** }
*/

/*
** @desc Extract decimal value from 2 bytes.
** @desc 00 2a would be translated as 42.
** @param int byte_1 - starting byte of 2 bytes
** @param byte_1 is used to access specific byte
** @param from the arena or the memory where executables are placed.
** @return int as decimal value of 2 bytes
*/

int			extract_2_bytes(int byte_1)
{
	int				i;
	unsigned		tmp;
	int				res;
	unsigned char	*s;

	s = save_arena(NULL);
	i = 0;
	tmp = 0;
	while (i < 2)
	{
		tmp = tmp << 8;
		tmp |= s[byte_1 % 4096];
		i++;
		byte_1++;
	}
	res = (short)tmp;
	return (res);
}

/*
** int		extract_1_byte(int byte_1)
** {
** 	unsigned char	*arena;
** 	arena = save_arena(NULL);
** 	return (arena[byte_1] % MEM_SIZE);
** }
*/

/*
** @desc Extract decimal value from 1 byte that corresponds
** @desc to possible register value.
** @desc 06 would be translated as 6.
** @param int byte_1 - target byte
** @param byte_1 is used to access specific byte
** @param from the arena or the memory where executables are placed.
** @return int as decimal value of the byte
*/

int			extract_1_byte(int byte_1)
{
	int				i;
	unsigned		tmp;
	int				res;
	unsigned char	*s;

	s = save_arena(NULL);
	byte_1 = byte_1 % 4096;
	s = &s[byte_1];
	i = 0;
	tmp = 0;
	while (i < 1)
	{
		tmp = tmp << 8;
		tmp |= s[i];
		i++;
	}
	res = (char)tmp;
	return (res);
}
