/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   battle.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 10:13:04 by lskrauci       #+#    #+#                */
/*   Updated: 2019/09/06 13:49:25 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Launch functions to create arena space, place player
** @desc executables in it, set up globally necessary variables
** @desc like cycles_to_die and initialize carriages.
** @desc Then, launch a function that starts the game after setting up
** @desc the carriages.
** @param t_players **players - array of players structures2
** @return void
*/

void	battle(t_players **players, t_cw *data)
{
	unsigned char	*arena;
	t_carriage		**carriages;

	introduce_players(players);
	arena = create_arena();
	battle_assist(players, arena);
	last_player_live_id(last_player_id(players));
	cycles_to_die(0);
	carriages = initialize_carriages(players, arena);
	save_carriages(carriages);
	if (get_visual(0) == 1)
		handle_events();
	else
	{
		while (battle_execute() > 0)
		{
			if (data->save_d == 1
			&& data->dumpcycle == number_of_cycles(JUST_RETURN))
			{
				print_arena(arena);
				break ;
			}
		}
	}
	battle_finished(data, players);
}

void	battle_finished(t_cw *data, t_players **players)
{
	if (data->save_d == 0 ||
	(data->save_d == 1 && data->dumpcycle > number_of_cycles(JUST_RETURN)))
		print_winner(players, last_player_live_id(0));
}

void	battle_assist(t_players **players, unsigned char *arena)
{
	place_executables(players, arena);
	save_arena(arena);
	save_players(players);
}
