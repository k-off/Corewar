/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:38:24 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 14:38:26 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'sti' command is executed by carriage,
** @desc then address at Current Position + distance 1 + distance 2
** @desc receives value of the register.
** @param t_carriage *carriage - carriage structure
** @param int distance1 - distance 1 to get total destination
** @param int distance2 - distance 2 to get total destination
** @param int source_register_value - register value
** @return void
*/

void	carriage_sti(t_carriage *carriage,
		int distance1, int distance2, int source_register_value)
{
	int				target_location;
	unsigned char	*arena;

	target_location = (carriage->current_position +
	((distance1 + distance2) % IDX_MOD)) % 4096;
	if (target_location < 0)
		target_location = 4096 + target_location;
	arena = save_arena(NULL);
	if (get_visual(0))
	{
		set_colormap(target_location, carriage->r1,
		(unsigned char *)(&source_register_value),
		sizeof(source_register_value));
	}
	carriage_sti_assist(source_register_value, target_location, arena);
}

void	carriage_sti_assist(int source_register_value,
		int target_location, unsigned char *arena)
{
	unsigned char	byte_one;
	unsigned char	byte_two;
	unsigned char	byte_three;
	unsigned char	byte_four;

	byte_four = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_three = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_two = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_one = source_register_value & 255;
	arena[target_location % 4096] = byte_one;
	arena[(target_location + 1) % 4096] = byte_two;
	arena[(target_location + 2) % 4096] = byte_three;
	arena[(target_location + 3) % 4096] = byte_four;
}
