/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:21 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:23:23 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'ld' command is executed by carriage,
** @desc it validates argument byte to see if
** @desc argument types of argument 1 is either
** @desc direct or indirect and that argument 2 is valid register.
** @desc Then data is extracted and sent to carriage_ld for execution.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_ld_hub(t_carriage *carriage, unsigned char *arena)
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
			arg1 = carriage_ld_hub_assist(carriage);
		if (types->type1 == 2)
			arg2 = extract_1_byte(carriage->current_position + 6);
		else
			arg2 = extract_1_byte(carriage->current_position + 4);
		if (arg2 >= 1 && arg2 <= 16)
			carriage_ld(carriage, arg1, arg2);
	}
	free(types);
	carriage_jump(carriage);
}

int		carriage_ld_hub_assist(t_carriage *carriage)
{
	int	temp;
	int	arg1;

	temp = extract_2_bytes(carriage->current_position + 2);
	arg1 = (carriage->current_position +
	(temp % IDX_MOD)) % 4096;
	if (arg1 < 0)
		arg1 = 4096 + arg1;
	arg1 = extract_4_bytes(arg1);
	return (arg1);
}

/*
** @desc If 'ld' command is executed by carriage,
** @desc then it loads value argument into register argument.
** @desc Changes carry if necessary.
** @param t_carriage *carriage - carriage structure
** @param int value - value to be loaded into register
** @param int reg - register of carriage to receive value
** @return void
*/

void	carriage_ld(t_carriage *carriage, int value, int reg)
{
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	if (reg == 1)
		carriage->r1 = value;
	else if (reg == 2)
		carriage->r2 = value;
	else if (reg == 3)
		carriage->r3 = value;
	else if (reg == 4)
		carriage->r4 = value;
	else if (reg == 5)
		carriage->r5 = value;
	else if (reg == 6)
		carriage->r6 = value;
	else if (reg == 7)
		carriage->r7 = value;
	else if (reg == 8)
		carriage->r8 = value;
	else if (reg == 9)
		carriage->r9 = value;
	else
		carriage_ld_assist(carriage, value, reg);
}

void	carriage_ld_assist(t_carriage *carriage, int value, int reg)
{
	if (reg == 10)
		carriage->r10 = value;
	else if (reg == 11)
		carriage->r11 = value;
	else if (reg == 12)
		carriage->r12 = value;
	else if (reg == 13)
		carriage->r13 = value;
	else if (reg == 14)
		carriage->r14 = value;
	else if (reg == 15)
		carriage->r15 = value;
	else if (reg == 16)
		carriage->r16 = value;
}
