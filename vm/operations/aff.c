/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:28:09 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:28:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'aff' command is executed by carriage,
** @desc argument byte after operation code is validated
** @desc to see if argument passed in is a register.
** @desc then carriage_aff_hub extracts information
** @desc about the argument and determines whether
** @desc or not it is a valid register value.
** @desc So carriage_aff_hub extracts and validates
** @desc if argument is a register and sends order
** @desc to carriage_aff.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_aff_hub(t_carriage *carriage, unsigned char *arena)
{
	int	args_byte;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	args_byte = arena[(carriage->current_position + 1) % 4096];
	args_byte = args_byte >> 6;
	if ((args_byte & 3) == 1
	&& arena[carriage->current_position + 2] >= 1
	&& arena[carriage->current_position + 2] <= 16)
		carriage_aff(carriage, arena[carriage->current_position + 2]);
	carriage_jump(carriage);
}

/*
** @desc If 'aff' command is executed by carriage,
** @desc then takes value from 'reg' and displays it as character.
** @param t_carriage *carriage - carriage structure
** @param int reg - register of carriage to receive value from
** @return void
*/

void	carriage_aff(t_carriage *carriage, int reg)
{
	int	val;

	val = register_value(carriage, reg);
	ft_printf("Aff: %c\n", (char)val);
}

int		aff_calculate_jump(unsigned char *arena, int position)
{
	int	arg_byte;

	arg_byte = arena[position + 1];
	arg_byte = arg_byte >> 6;
	if ((arg_byte & 3) == 1)
		return (3);
	else if ((arg_byte & 3) == 2)
		return (6);
	else if ((arg_byte & 3) == 0)
		return (2);
	else
		return (4);
}
