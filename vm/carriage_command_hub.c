/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage_command_hub.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 12:00:49 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/19 12:00:51 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	carriage_command_hub_og(t_carriage *carriage,
		unsigned char *arena, unsigned int opcode)
{
	if (opcode == 1)
		carriage_live_hub(carriage, arena);
	else if (opcode == 2)
		carriage_ld_hub(carriage, arena);
	else if (opcode == 3)
		carriage_st_hub(carriage, arena);
	else if (opcode == 4)
		carriage_add_hub(carriage, arena);
	else if (opcode == 5)
		carriage_sub_hub(carriage, arena);
	else if (opcode == 6)
		carriage_and_hub(carriage, arena);
	else if (opcode == 7)
		carriage_or_hub(carriage, arena);
	else
		carriage_command_hub_assist(carriage, arena, opcode);
}

/*
** @desc When all carriages are scanned in each cycle, this function
** @desc executes current carriage operation by launching specific
** @desc function based on operation code or jumps to next operation
** @desc to extract information about new operation.
** @desc If operation was executed in previous cycle, then within current
** @desc cycle the carriage simply jumps forward to next operation.
** @param t_carriage *carriage - carriage structure
** @return void
*/

void		carriage_command_hub(t_carriage *carriage)
{
	unsigned int	opcode;
	unsigned char	*arena;

	arena = save_arena(NULL);
	if (carriage->cycles_before_execution == 0)
	{
		carriage->current_opcode = arena[carriage->current_position];
		carriage->cycles_before_execution =
		cycles_before_execution(carriage->current_opcode);
	}
	carriage->cycles_before_execution = carriage->cycles_before_execution - 1;
	if (carriage->cycles_before_execution != 0)
		return ;
	opcode = carriage->current_opcode;
	carriage_command_hub_og(carriage, arena, opcode);
}

void		carriage_command_hub_assist(t_carriage *carriage,
		unsigned char *arena, unsigned int opcode)
{
	if (opcode == 8)
		carriage_xor_hub(carriage, arena);
	else if (opcode == 9)
		carriage_zjmp_hub(carriage, arena);
	else if (opcode == 10)
		carriage_ldi_hub(carriage, arena);
	else if (opcode == 11)
		carriage_sti_hub(carriage, arena);
	else if (opcode == 12)
		carriage_fork_hub(carriage, arena);
	else if (opcode == 13)
		carriage_lld_hub(carriage, arena);
	else if (opcode == 14)
		carriage_lldi_hub(carriage, arena);
	else if (opcode == 15)
		carriage_lfork_hub(carriage, arena);
	else if (opcode == 16)
		carriage_aff_hub(carriage, arena);
	else
	{
		carriage->jump = 1;
		carriage_jump(carriage);
	}
}
