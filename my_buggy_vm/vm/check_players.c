/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_players.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void sort_players3(t_player **players, t_player *sort[])
{
	int			i;
	t_player	*res;
	t_player	*tmp;

	res = sort[1];
	tmp = res;
	i = 2;
	while (i < MAX_PLAYERS + 1 && sort[i] != NULL)
	{
		if (sort[i] != NULL)
		{
			sort[i]->next = NULL;
			tmp->next = sort[i];
			tmp = tmp->next;
		}
		i++;
	}
	*players = res;
}

static void sort_players2(t_player **players, t_player *sort[])
{
	t_player	*tmp;
	int			i;

	tmp = *players;
	while (tmp != NULL)
	{
		if (tmp->id_custom == 0)
		{
			i = 1;
			while (sort[i] != 0)
				i++;
			sort[i] = tmp;
			sort[i]->id_p = i;
		}
		tmp = tmp->next;
	}
	i = 2;
	while (i < MAX_PLAYERS + 1)
	{
		if (sort[i] != 0 && sort[i - 1] == 0)
			exit(!!ft_printf("ERROR: '-n %d' is not in sequence\n", i));
		i++;
	}
	sort_players3(players, sort);
}

static void	sort_players(t_player **players)
{
	t_player	*tmp;
	t_player	*sort[MAX_PLAYERS + 1];

	tmp = *players;
	ft_bzero(sort, sizeof(sort));
	while (tmp != NULL)
	{
		if (tmp->id_custom != 0)
		{
			if (sort[tmp->id_custom] == NULL)
			{
				sort[tmp->id_custom] = tmp;
				sort[tmp->id_custom]->id_p = tmp->id_custom;
			}
			else
				exit(!!ft_printf("ERROR: '-n%d' flag twice\n", tmp->id_custom));
		}
		tmp = tmp->next;
	}
	sort_players2(players, sort);
}

void		set_cursor(t_player *tmp, t_cursor **cursors)
{
	t_cursor	*tmp_cursor;

	tmp_cursor = (t_cursor*)ft_memalloc(sizeof(t_cursor));
	tmp_cursor->next = *cursors;
	if (tmp_cursor->next == NULL)
		tmp_cursor->id_c = 1;
	else
		tmp_cursor->id_c = tmp_cursor->next->id_c + 1;
	*cursors = tmp_cursor;
	tmp_cursor->pos = tmp->pos;
	tmp_cursor->reg[1] = -tmp->id_p;
}

void		check_players(t_player **players, t_cursor **cursors, int plr_qty)
{
	t_player	*tmp;

	sort_players(players);
	tmp = *players;
	while (tmp)
	{
		if (tmp->name == NULL)
			exit(!!ft_printf("ERROR: player %d name not set\n", tmp->id_p));
		if (tmp->comment == NULL)
			exit(!!ft_printf("ERROR: player %d no comment\n", tmp->comment));
		if (tmp->id_p > MAX_PLAYERS || tmp->id_p < 1)
			exit(!!ft_printf("ERROR: player %d id is wrong\n", tmp->comment));
		if (tmp->exe == NULL || tmp->exe[0] < 1 || tmp->exe[0] > 16)
			exit(!!ft_printf("ERROR: player %d is not executable\n", tmp->exe));
		tmp->pos = (MEM_SIZE / plr_qty) * (tmp->id_p - 1);
		set_cursor(tmp, cursors);
		tmp = tmp->next;
	}
	board_setup(get_game(NULL));
}
