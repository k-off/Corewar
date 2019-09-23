/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriages.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 11:40:15 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/17 11:40:17 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Create carriage for specific player
** @param t_players *player - array of player's structure
** @param unsigned char *arena - arena with filled executables
** @param int position - index of player's executable within arena
** @return t_carriage * as carriage for specific player
*/

t_carriage	*carriage_origin(t_players *player,
			unsigned char *arena, int position)
{
	static int	carriage_id;
	t_carriage	*carriage;

	carriage_id = carriage_id + 1;
	carriage = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	carriage->id = carriage_id;
	carriage->carry = 0;
	carriage->current_position = position % MEM_SIZE;
	if (carriage->current_position < 0)
		carriage->current_position = 4096 + carriage->current_position;
	carriage->current_opcode = arena[position];
	carriage->cycle_live_reported = 0;
	carriage->cycles_before_execution =
	cycles_before_execution(carriage->current_opcode);
	carriage->jump = calculate_jump(carriage->current_opcode, arena, position);
	carriage->r1 = player->id * -1;
	initialize_registers(carriage);
	return (carriage);
}

/*
** @desc Create empty array for carriages
** @param void
** @return t_carriage ** as array capable of storing 4 carriage structures
*/

t_carriage	**carriages_array(void)
{
	int			i;
	int			count;
	t_carriage	**carriages;

	i = 0;
	count = 1000000;
	carriages = (t_carriage **)ft_memalloc(sizeof(t_carriage*) * count);
	while (i < count)
	{
		carriages[i] = NULL;
		i++;
	}
	return (carriages);
}

/*
** @desc Create carriage for each player within an array. Then,
** @desc given a player create corresponding carriage and point it
** @desc to specific place in arena at start of player's executable.
** @param t_players **players - array of players structures
** @param unsigned char *arena - arena with filled executables
** @return t_carriage ** as array of carriages for each player in order
** @return such that last player is the first in array.
*/

t_carriage	**initialize_carriages(t_players **players, unsigned char *arena)
{
	int			i;
	int			position;
	int			players_count;
	int			players_field_size;
	t_carriage	**carriages;

	i = 0;
	position = 0;
	players_count = count_players(players);
	players_field_size = MEM_SIZE / players_count;
	carriages = carriages_array();
	while (i < players_count)
	{
		carriages[i] = carriage_origin(players[i], arena, position);
		position = position + players_field_size;
		i++;
	}
	if (players_count != 1)
		reverse_carriage_array(carriages, players_count);
	return (carriages);
}

/*
** @desc Check which carriages have not reported live within last
** @desc cycles_to_die cycles and remove such a carriage.
** @desc If carriage that can be considered as dead is encountered,
** @desc free it and move all following pointers one step to left.
** @param t_carriage **carriages - array of carriages
** @param int current_cycle - current cycle
** @param int cycles_to_die - cycles to die acting as time window
** @param for carriages to report live at least once.
** @return void
*/

void		remove_dead_carriages(t_carriage **carriages,
			int current_cycle, int cycles_to_die)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (carriages[count] != NULL)
		count++;
	while (i < count)
	{
		if (carriages[i] != NULL &&
		carriages[i]->cycle_live_reported <= current_cycle - cycles_to_die)
		{
			remove_dead_carriages_assist(&i, carriages, &count);
			continue;
		}
		i++;
	}
}

void		remove_dead_carriages_assist(int *i,
			t_carriage **carriages, int *count)
{
	int	j;

	j = *i;
	free(carriages[*i]);
	while (carriages[j] != NULL)
	{
		carriages[j] = carriages[j + 1];
		j++;
	}
	(*count)--;
}
