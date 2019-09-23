/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lld.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:27:48 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:27:49 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'lld' command is executed by carriage,
** @desc then carriage_lld_hub extracts information
** @desc about the arguments and determines their types
** @desc extract_types_2 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If and has received valid 2 arguments, it extracts
** @desc argument values and sends them to carriage_lld function,
** @desc which actually executes the command. Thus carriage_lld_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_lld_hub(t_carriage *carriage, unsigned char *arena)
{
	int		arg1;
	int		arg2;
	t_types	*types;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	types = extract_types_2(arena[(carriage->current_position + 1) % 4096]);
	if ((types->type1 == 2 || types->type1 == 3) && types->type2 == 1)
	{
		if (types->type1 == 2)
			arg1 = extract_4_bytes(carriage->current_position + 2);
		else
			arg1 = carriage_lld_hub_assist(carriage);
		if (types->type1 == 2)
			arg2 = extract_1_byte(carriage->current_position + 6);
		else
			arg2 = extract_1_byte(carriage->current_position + 4);
		if (arg2 >= 1 && arg2 <= 16)
			carriage_lld(carriage, arg1, arg2);
	}
	free(types);
	carriage_jump(carriage);
}

int		carriage_lld_hub_assist(t_carriage *carriage)
{
	int	temp;
	int	arg1;

	temp = extract_2_bytes(carriage->current_position + 2);
	arg1 = (carriage->current_position + temp) % 4096;
	if (arg1 < 0)
		arg1 = 4096 + arg1;
	arg1 = extract_4_bytes(arg1);
	return (arg1);
}

/*
** @desc If 'lld' command is executed by carriage,
** @desc then it loads value argument into register argument.
** @desc It's difference from 'ld' is that if type of value received
** @desc was originally T_IND, then to get address of value,
** @desc instead of going to Current Position + T_IND % IDX_MOD,
** @desc Current Position + T_IND is used instead.
** @desc Changes carry if necessary.
** @param t_carriage *carriage - carriage structure
** @param int value - value to be loaded into register
** @param int reg - register of carriage to receive value
** @return void
*/

void	carriage_lld(t_carriage *carriage, int value, int reg)
{
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	register_write(carriage, reg, value);
}
