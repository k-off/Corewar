/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriages_support.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 13:52:06 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/17 13:52:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Because register 1 within carriage store's players ID,
** @desc it is not set to 0, but all other 15 registers are.
** @param t_carriage *carriage - structure storing a carriage
** @return void
*/

void	initialize_registers(t_carriage *carriage)
{
	carriage->r2 = 0;
	carriage->r3 = 0;
	carriage->r4 = 0;
	carriage->r5 = 0;
	carriage->r6 = 0;
	carriage->r7 = 0;
	carriage->r8 = 0;
	carriage->r9 = 0;
	carriage->r10 = 0;
	carriage->r11 = 0;
	carriage->r12 = 0;
	carriage->r13 = 0;
	carriage->r14 = 0;
	carriage->r15 = 0;
	carriage->r16 = 0;
}

/*
** @desc Based on operation code, find out cycles before execution
** @desc aka how many cycles does it take before carriage executes
** @desc operation it is standing on.
** @param unsigned int opcode - operation code
** @return int as cycles before execution
** @return if operation code is invalid return 0 as carriage
** @return simply needs to move forward
*/

int		cycles_before_execution(unsigned int opcode)
{
	if (opcode == 1 || opcode == 4 || opcode == 5 || opcode == 13)
		return (10);
	else if (opcode == 2 || opcode == 3)
		return (5);
	else if (opcode == 6 || opcode == 7 || opcode == 8)
		return (6);
	else if (opcode == 9)
		return (20);
	else if (opcode == 10 || opcode == 11)
		return (25);
	else if (opcode == 12)
		return (800);
	else if (opcode == 14)
		return (50);
	else if (opcode == 15)
		return (1000);
	else if (opcode == 16)
		return (2);
	else
		return (1);
}

/*
** @desc Reverse carriages within carriages array, because
** @desc last carriage should be at the start.
** @param t_carriage **carriages - array of carriages
** @param int players_count - count of players
** @return void
*/

void	reverse_carriage_array(t_carriage **carriages, int players_count)
{
	int			start;
	int			end;
	int			times;
	t_carriage	*temp;

	start = 0;
	end = players_count - 1;
	if (players_count == 2 || players_count == 3)
		times = 1;
	else
		times = 2;
	while (times != 0)
	{
		temp = carriages[start];
		carriages[start] = carriages[end];
		carriages[end] = temp;
		start = start + 1;
		end = end - 1;
		times = times - 1;
	}
}

/*
** @desc For T_DIR (Direct) argument, return it's size based on operation.
** @param t_instruction *instruction - node containing instruction
** @return int as label size indicating T_DIR size
*/

int		single_arg_dir(unsigned int opcode)
{
	if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12
	|| opcode == 14 || opcode == 15)
		return (2);
	return (4);
}

/*
** @desc Check if register number is between 1 and 16
** @param unsigned char reg - register to be checked
** @return int 1 if register is valid
** @return int 0 if register is not valid
*/

int		is_reg_num(unsigned char reg)
{
	if (reg >= 1 && reg <= 16)
		return (1);
	return (0);
}
