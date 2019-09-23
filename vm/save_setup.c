/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 10:41:51 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/17 10:41:52 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Save name of the player that was last reported live by it's carriage.
** @desc Very first time name of player with highest ID is saved.
** @desc Next, to update variable new player name is provided.
** @desc If player name is NULL, then it is understood that we want to get
** @desc name we had saved previously.
** @param char *player - name of player last reported live
** @return NULL very first time player name is saved or updated
** @return char * to player name if player parameter is NULL
*/

/*
**char    *last_player_live(char *player)
**{
**	static char *player_name;
**
**	if (player_name == NULL)
**	{
**		player_name = ft_strdup(player);
**		return (NULL);
**	}
**	else if (player != NULL)
**	{
**		free(player_name);
**		player_name = ft_strdup(player);
**		return (NULL);
**	}
**	return (player_name);
**}
*/

/*
** @desc Save ID of the player that was last reported live by it's carriage.
** @desc Very first time ID of player last in players array is saved.
** @desc Next, to update variable new player ID is provided.
** @desc If player ID is 0, then it is understood that we want to get
** @desc ID we had saved previously.
** @desc It also checks whether or not received ID is for a valid
** @desc player and we multiple reported_id by -1 to get it positive
** @desc to correspond to some player's ID. We save it also as positive number
** @param int reported_id  - ID of player last reported live
** @return 0 very first time player name is saved or updated
** @return int to last live player ID if player parameter is 0
*/

int	last_player_live_id(int reported_id)
{
	int			i;
	static int	saved_id;
	t_players	**players;

	i = 0;
	if (saved_id == 0)
		saved_id = reported_id;
	else if (reported_id != 0)
	{
		players = save_players(NULL);
		while (players[i] != NULL && i < 4)
		{
			if (players[i]->id == (reported_id * -1))
			{
				saved_id = reported_id * -1;
				return (saved_id);
			}
			i++;
		}
	}
	return (saved_id);
}

/*
** @desc Save number of cycles since beginning of the game. Starts at 0.
** @desc If update parameter is 1, then we increase cycles by 1.
** @param int update - indicates whether or not to increase cycles.
** @param If it is 0, we just want to retrieve cycles elapsed. If it
** @param is 1, we update cycles.
** @return int cycles as cycles elapsed since start of game
*/

int	number_of_cycles(int update)
{
	static int cycles;

	if (update == 1)
	{
		cycles++;
		return (cycles);
	}
	return (cycles);
}

/*
** @desc Save number of times live has been reported within
** @desc cycles_to_die cycles.
** @desc If update parameter is 1, then we increase live performed by 1.
** @desc If update parameter is 2, then we reset live performed to 0.
** @param int update - indicates whether or not to increase live performed,
** @param or to reset it to 0 when new period of cycles_to_die starts.
** @param If it is 0, we just want to retrieve times live was performed.
** @param If it 1, we want to increase by 1 times that live was performed.
** @param If it -1, we want to reset live performed count to 0.
** @return int live_performed as live performed within cycles_to_die cycles.
*/

int	number_of_live_performed(int update)
{
	static int live_performed;

	if (update == 1)
	{
		live_performed++;
		return (live_performed);
	}
	else if (update == -1)
	{
		live_performed = 0;
		return (0);
	}
	return (live_performed);
}

/*
** @desc Save current cycles_to_die.
** @desc First time function is called, save '1536' as starting cycles_to_die.
** @desc If decrease parameter is 1, then we want to decrease
** @desc cycles_to_die by 50. If it is not, then we are interested in current
** @desc amount of cycles_to_die.
** @param int decrease - indicates whether or not to decrease cycles_to_die.
** @return int cycles_to_die as current cycles_to_die.
*/

int	cycles_to_die(int decrease)
{
	static int cycles_to_die;

	if (cycles_to_die == 0)
		cycles_to_die = CYCLES_TO_DIE;
	else if (decrease == 1)
		cycles_to_die = cycles_to_die - 50;
	return (cycles_to_die);
}

/*
** @desc Save number of checks performed. Check is defined as
** @desc every cycles_to_die cycles check if carriages are alive.
** @desc If cycles_to_die is <= 0, then check is performed after
** @desc each cycle.
** @desc This comes into play if 10 times checks were performed
** @desc and less than 21 'live's was performed. Then decrease
** @desc cycles_to_die by 50 anyway.
** @desc Checks are reset to 0 every 10 times that check is performed.
** @param int update - indicates whether or not to increase checks.
** @param If it is 0, we just want to retrieve checks done. If it
** @param is 1, we update checks.
** @return int checks as checks elapsed since start of game
*/

int	number_of_checks(int update)
{
	static int checks;

	if (update == 1)
	{
		checks++;
		return (checks);
	}
	else if (update == -1)
		checks = 0;
	return (checks);
}
