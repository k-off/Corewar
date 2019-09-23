/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:15 by lskrauci       #+#    #+#                */
/*   Updated: 2019/09/11 18:57:19 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'live' command is executed by carriage,
** @desc this function extract direct value T_DIR to get
** @desc player id reported by live. Then this data is sent
** @desc for execution to carriage_live.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_live_hub(t_carriage *carriage, unsigned char *arena)
{
	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	carriage_live(carriage, extract_4_bytes(carriage->current_position + 1));
	carriage_jump(carriage);
}

void	valid_id_player(t_players **players, int id)
{
	int		i;
	int		l_flag;

	i = 0;
	l_flag = save_l_flag(NULL);
	if (l_flag != 1)
		return ;
	while (i < 4 && players[i] != NULL)
	{
		if (players[i]->id == (id * -1))
		{
			ft_printf("A process shows that player %d (%s) is alive\n",
			players[i]->id, players[i]->name);
			break ;
		}
		i++;
	}
}

/*
** @desc If 'live' command is executed by carriage,
** @desc then it's cycle that it was reported live is updated.
** @desc It also reports this to function that counts overall
** @desc how many times 'live' has been called in last
** @desc cycles_do_die cycles.
** @param t_carriage *carriage - carriage structure
** @param int id - id of player whose carriage reported it 'live'
** @return void
*/

void	carriage_live(t_carriage *carriage, int id)
{
	int			i;
	t_players	**players;

	i = 0;
	players = save_players(NULL);
	carriage->cycle_live_reported = number_of_cycles(0);
	number_of_live_performed(1);
	last_player_live_id(id);
	valid_id_player(players, id);
}
