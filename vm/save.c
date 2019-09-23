/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 20:51:10 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/18 20:51:12 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Save address of arena
** @param unsgined char *arena - address of arena
** @return char *arena as address of arena
*/

unsigned char	*save_arena(unsigned char *arena)
{
	static unsigned char	*saved_arena;

	if (saved_arena == NULL)
		saved_arena = arena;
	return (saved_arena);
}

/*
** @desc Save address of carriages array.
** @desc It is done so that we can in the same address
** @desc insert a new carriage.
** @param t_carriage ***carriages - address of carriages array
** @return t_carriage *** as address of carriages array
*/

t_carriage		**save_carriages(t_carriage **carriages)
{
	static t_carriage		**saved_carriages;

	if (saved_carriages == NULL)
		saved_carriages = carriages;
	return (saved_carriages);
}

/*
** @desc Save address of players array.
** @desc It is done so that we can access players array anywhere.
** @param t_players **players - address of players array
** @return t_players ** as address of players array
*/

t_players		**save_players(t_players **players)
{
	static t_players		**saved_players;

	if (saved_players == NULL)
		saved_players = players;
	return (saved_players);
}
