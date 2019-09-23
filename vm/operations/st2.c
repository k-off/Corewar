/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st2.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:35:09 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 14:35:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'st' command is executed by carriage,
** @desc then it loads value from register into register or arena.
** @desc Value is loaded from source register to either another
** @desc register or (Current position + T_IND) % IDX_MOD place in arena.
** @param t_carriage *carriage - carriage structure
** @param int source_register - source register
** @param int destination_register - if destination is not register,
** @param then this is set to -1.
** @param int indirect - if destination is not indirect,
** @param then this is set to -1.
** @return void
*/

void	carriage_st(t_carriage *carriage,
		int source_register, int destination_register, int indirect)
{
	unsigned char	*arena;

	arena = save_arena(NULL);
	if (destination_register != -1 && indirect == -1)
		carriage_st_register(carriage, source_register, destination_register);
	else if (indirect != -1 && destination_register == -1)
		carriage_st_indirect(carriage, source_register, indirect, arena);
}

void	carriage_st_register(t_carriage *carriage,
		int source_register, int destination_register)
{
	if (destination_register == 1)
		carriage->r1 = register_value(carriage, source_register);
	else if (destination_register == 2)
		carriage->r2 = register_value(carriage, source_register);
	else if (destination_register == 3)
		carriage->r3 = register_value(carriage, source_register);
	else if (destination_register == 4)
		carriage->r4 = register_value(carriage, source_register);
	else if (destination_register == 5)
		carriage->r5 = register_value(carriage, source_register);
	else if (destination_register == 6)
		carriage->r6 = register_value(carriage, source_register);
	else if (destination_register == 7)
		carriage->r7 = register_value(carriage, source_register);
	else if (destination_register == 8)
		carriage->r8 = register_value(carriage, source_register);
	else if (destination_register == 9)
		carriage->r9 = register_value(carriage, source_register);
	else if (destination_register == 10)
		carriage->r10 = register_value(carriage, source_register);
	else if (destination_register == 11)
		carriage->r11 = register_value(carriage, source_register);
	else
		carriage_st_register_assist(carriage,
		source_register, destination_register);
}

void	carriage_st_register_assist(t_carriage *carriage,
		int source_register, int destination_register)
{
	if (destination_register == 12)
		carriage->r12 = register_value(carriage, source_register);
	else if (destination_register == 13)
		carriage->r13 = register_value(carriage, source_register);
	else if (destination_register == 14)
		carriage->r14 = register_value(carriage, source_register);
	else if (destination_register == 15)
		carriage->r15 = register_value(carriage, source_register);
	else if (destination_register == 16)
		carriage->r16 = register_value(carriage, source_register);
}

void	carriage_st_indirect(t_carriage *carriage,
		int source_register, int indirect, unsigned char *arena)
{
	unsigned char	byte_one;
	unsigned char	byte_two;
	unsigned char	byte_three;
	unsigned char	byte_four;
	int				source_register_value;

	source_register_value = register_value(carriage, source_register);
	if (get_visual(0))
	{
		set_colormap(indirect, carriage->r1,
		(unsigned char*)(&source_register_value),
		sizeof(source_register_value));
	}
	byte_four = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_three = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_two = source_register_value & 255;
	source_register_value = source_register_value >> 8;
	byte_one = source_register_value & 255;
	arena[indirect % 4096] = byte_one;
	arena[(indirect + 1) % 4096] = byte_two;
	arena[(indirect + 2) % 4096] = byte_three;
	arena[(indirect + 3) % 4096] = byte_four;
}
