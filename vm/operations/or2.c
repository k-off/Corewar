/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or2.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:26:05 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 14:26:06 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'or' command is executed by carriage,
** @desc then it performs bitwise or operation on
** @desc num1 and num2 and writes result to the register.
** @desc Changes carry if necessary.
** @param t_carriage *carriage - carriage structure
** @param int num1 - number 1 for bitwise or operation
** @param int num2 - number 2 for bitwise or operation
** @param int reg - destination register
** @return void
*/

void	carriage_or(t_carriage *carriage, int num1, int num2, int reg)
{
	register_write(carriage, reg, (num1 | num2));
	if ((num1 | num2) == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}

void	carriage_or_hub_assist_4(t_carriage *carriage,
		t_types *types, int *arg2, int *temp)
{
	if (types->type1 == 1)
	{
		*temp = extract_2_bytes(carriage->current_position + 3);
		*arg2 = extract_4_bytes((carriage->current_position +
		(*temp % IDX_MOD)) % 4096);
	}
	else if (types->type1 == 2)
	{
		*temp = extract_2_bytes(carriage->current_position + 6);
		*arg2 = extract_4_bytes((carriage->current_position +
		(*temp % IDX_MOD)) % 4096);
	}
	else if (types->type1 == 3)
	{
		*temp = extract_2_bytes(carriage->current_position + 4);
		*arg2 = extract_4_bytes((carriage->current_position +
		(*temp % IDX_MOD)) % 4096);
	}
}
