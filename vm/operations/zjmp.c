/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zjmp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:24:00 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:24:04 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'zjmp' command is executed by carriage,
** @desc then carriage_zjmp_hub extracts information
** @desc about direct T_DIR argument and calls carriage_zjmp.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_zjmp_hub(t_carriage *carriage, unsigned char *arena)
{
	if (carriage->carry == 0)
	{
		carriage->jump =
		calculate_jump(carriage->current_opcode, arena,
		carriage->current_position);
		carriage_jump(carriage);
		return ;
	}
	carriage_zjmp(carriage, extract_2_bytes(carriage->current_position + 1));
	carriage_jump(carriage);
}

/*
** @desc If 'zjmp' command is executed by carriage,
** @desc then it jumps to direct_value % IDX_MOD for next operation.
** @desc Zjmp only works if carry of carriage is 1, not 0.
** @param t_carriage *carriage - carriage structure
** @param int direct_value - direct value read from arena
** @return void
*/

void	carriage_zjmp(t_carriage *carriage, int direct_value)
{
	carriage->jump = direct_value % IDX_MOD;
}
