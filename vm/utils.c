/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 11:27:09 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/17 11:27:10 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Given array of players, check which is last added player.
** @param t_players **players - array of players structures
** @return char * as address of last added player name
*/

char	*last_player_name(t_players **players)
{
	int i;

	i = 0;
	while (players[i + 1] != NULL && i < 3)
		i++;
	return (players[i]->name);
}

/*
** @desc Given array of players, check which is last added player.
** @param t_players **players - array of players structures
** @return char * as address of last added player name
*/

int		last_player_id(t_players **players)
{
	int i;

	i = 0;
	while (players[i + 1] != NULL && i < 3)
		i++;
	return (players[i]->id);
}

/*
** @desc Given array of players, count how many players exist.
** @param t_players **players - array of players structures
** @return int as count of players
*/

int		count_players(t_players **players)
{
	int	count;

	count = 0;
	while (players[count] && count < 4)
		count++;
	return (count);
}

/*
** @desc This is a function that helps to compare the magic header.
** @desc It was reading the bytes reversed per two.
** @param char *s - string to be reversed in groups of two characters
** @return void
*/

void	rev_per_two_char(char *s)
{
	int		i;
	char	tmp;

	i = 0;
	while (s[i])
	{
		tmp = s[i];
		s[i] = s[i + 1];
		s[i + 1] = tmp;
		i += 2;
	}
}

/*
** @desc Capitalize string for atoi function
** @param char *tmp - string to capitalize
** @return void
*/

void	capitalize_atoi(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= 'a' && tmp[i] <= 'z')
			tmp[i] = tmp[i] - 32;
		i++;
	}
}
