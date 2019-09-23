/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:27:43 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:27:44 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'fork' command is executed by carriage,
** @desc carriage_fork_hub extracts direct value T_DIR
** @desc and calls carriage_fork to create new carriage.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_fork_hub(t_carriage *carriage, unsigned char *arena)
{
	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	carriage_fork(carriage, extract_2_bytes(carriage->current_position + 1));
	carriage_jump(carriage);
}

/*
** @desc If 'fork' command is executed by carriage,
** @desc then a copy of carriage is created and placed at
** @desc direct_value % IDX_MOD.
** @desc We create strucutre player for transmitting
** @desc player's ID of current carriage to next carriage.
** @param t_carriage *carriage - carriage structure
** @param int distance - direct argument indicating where to place carriage
** @return void
*/

void	carriage_fork(t_carriage *carriage, int distance)
{
	unsigned char	*arena;
	t_carriage		**saved_carriages;
	t_carriage		*new_carriage;
	t_players		*player;

	arena = save_arena(NULL);
	saved_carriages = save_carriages(NULL);
	player = (t_players*)malloc(sizeof(t_players));
	player->id = carriage->r1 * -1;
	new_carriage = carriage_origin(player,
	arena, carriage->current_position + (distance % IDX_MOD));
	free(player);
	shift_carriages(saved_carriages);
	new_carriage->carry = carriage->carry;
	copy_registers(carriage, new_carriage);
	new_carriage->cycle_live_reported = carriage->cycle_live_reported;
	saved_carriages[0] = new_carriage;
	new_carriage->cycles_before_execution = 0;
}
