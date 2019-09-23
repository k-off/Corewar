/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:08:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:08:35 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Insert executables of players in arena after calculating
** @desc how executables should be spaced.
** @param t_players **players - array of players structures
** @param unsigned char *arena - empty arena string
** @return void
*/

void			place_executables(t_players **players, unsigned char *arena)
{
	int	i;
	int	players_count;
	int	players_field_size;

	i = 0;
	players_count = count_players(players);
	players_field_size = MEM_SIZE / players_count;
	while (i < players_count)
	{
		ft_memcpy(arena, players[i]->executable, CHAMP_MAX_SIZE);
		set_colormap(i * players_field_size, players[i]->id,
		(unsigned char*)players[i]->executable, players[i]->executable_size);
		arena = arena + players_field_size;
		i++;
	}
}

/*
** @desc Create arena space of MEM_SIZE aka 4096
** @param void
** @return string of length MEM_SIZE with values initialized to 0
*/

unsigned char	*create_arena(void)
{
	int				i;
	unsigned char	*arena;

	i = 0;
	arena = (unsigned char *)ft_memalloc(sizeof(unsigned char) * MEM_SIZE + 1);
	while (i < MEM_SIZE)
	{
		arena[i] = 0;
		i++;
	}
	arena[i] = '\0';
	return (arena);
}

void			shift_carriages(t_carriage **saved_carriages)
{
	int	i;

	i = 0;
	while (saved_carriages[i + 1] != NULL)
		i++;
	while (i >= 0)
	{
		saved_carriages[i + 1] = saved_carriages[i];
		i = i - 1;
	}
}

void			copy_registers(t_carriage *src, t_carriage *dst)
{
	dst->r1 = src->r1;
	dst->r2 = src->r2;
	dst->r3 = src->r3;
	dst->r4 = src->r4;
	dst->r5 = src->r5;
	dst->r6 = src->r6;
	dst->r7 = src->r7;
	dst->r8 = src->r8;
	dst->r9 = src->r9;
	dst->r10 = src->r10;
	dst->r11 = src->r11;
	dst->r12 = src->r12;
	dst->r13 = src->r13;
	dst->r14 = src->r14;
	dst->r15 = src->r15;
	dst->r16 = src->r16;
}

/*
** @desc Track how many carriages every existed.
** @param is 1, we update checks.
** @return int checks as checks elapsed since start of game
*/

int				all_carriages_count(int update)
{
	static int carriages;

	if (carriages == 0)
		carriages = update;
	else if (update == 1)
		carriages++;
	return (carriages);
}
