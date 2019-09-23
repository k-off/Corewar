/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 19:40:12 by lskrauci       #+#    #+#                */
/*   Updated: 2019/09/15 16:59:37 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Checks if the l flag is present.
** @param *data - struct were we save some data provided by the arg.
** @return 1 or 0.
*/

int		save_l_flag(t_cw *data)
{
	static int l;

	if (data != NULL && data->lflag == 1)
		l = 1;
	return (l);
}

/*
** @desc Extract value from a register of carriage
** @param t_carriage *carriage - carriage storing specific register
** @param int reg - register which value we want to know
** @return int as 'reg' register value
*/

int		register_value(t_carriage *carriage, int reg)
{
	if (reg == 1)
		return (carriage->r1);
	else if (reg == 2)
		return (carriage->r2);
	else if (reg == 3)
		return (carriage->r3);
	else if (reg == 4)
		return (carriage->r4);
	else if (reg == 5)
		return (carriage->r5);
	else if (reg == 6)
		return (carriage->r6);
	else if (reg == 7)
		return (carriage->r7);
	else if (reg == 8)
		return (carriage->r8);
	else if (reg == 9)
		return (carriage->r9);
	else if (reg == 10)
		return (carriage->r10);
	else if (reg == 11)
		return (carriage->r11);
	else
		return (register_value_assist(carriage, reg));
}

int		register_value_assist(t_carriage *carriage, int reg)
{
	if (reg == 12)
		return (carriage->r12);
	else if (reg == 13)
		return (carriage->r13);
	else if (reg == 14)
		return (carriage->r14);
	else if (reg == 15)
		return (carriage->r15);
	else if (reg == 16)
		return (carriage->r16);
	return (0);
}

/*
** @desc Write value to a register of carriage
** @param t_carriage *carriage - carriage storing destination register
** @param int destination_register - destination register of carriage
** @param int value - value to be written to the register
** @return void
*/

void	register_write(t_carriage *carriage,
		int destination_register, int value)
{
	if (destination_register == 1)
		carriage->r1 = value;
	else if (destination_register == 2)
		carriage->r2 = value;
	else if (destination_register == 3)
		carriage->r3 = value;
	else if (destination_register == 4)
		carriage->r4 = value;
	else if (destination_register == 5)
		carriage->r5 = value;
	else if (destination_register == 6)
		carriage->r6 = value;
	else if (destination_register == 7)
		carriage->r7 = value;
	else if (destination_register == 8)
		carriage->r8 = value;
	else if (destination_register == 9)
		carriage->r9 = value;
	else if (destination_register == 10)
		carriage->r10 = value;
	else
		register_write_assist(carriage, destination_register, value);
}

void	register_write_assist(t_carriage *carriage,
		int destination_register, int value)
{
	if (destination_register == 11)
		carriage->r11 = value;
	else if (destination_register == 12)
		carriage->r12 = value;
	else if (destination_register == 13)
		carriage->r13 = value;
	else if (destination_register == 14)
		carriage->r14 = value;
	else if (destination_register == 15)
		carriage->r15 = value;
	else if (destination_register == 16)
		carriage->r16 = value;
}
