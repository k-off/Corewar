/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			operation_live(t_cursor *cursor, t_game *game)
{
	int			id_p;
	t_player	*player;

	game->check->lives_performed++;
	cursor->last_alive = game->check->cur_cycle;
	id_p = -cursor->reg[1];
	player = game->players;
	while (player)
	{
		if (player->id_p == id_p)
			break;
		player = player->next;
	}
	if (player)
		game->last_alive = player;
	return (1);
}

int			operation_ld(t_cursor *cursor, t_game *game)
{
	int		pos;

	if (cursor->op.argument_type[0] == 1 || cursor->op.argument_type[1] != 1)
		exit(ft_printf("ERROR: operation LD: %d %d %d as parameter types.\n",
				cursor->op.argument_type[0], cursor->op.argument_type[1],
				cursor->op.argument_type[2]));
	if (cursor->op.argument_type[0] == 2)
		cursor->reg[cursor->op.argument[1]] = cursor->op.argument[0];
	else if (cursor->op.argument_type[0] == 4)
	{
		pos = (cursor->op.argument[0] % IDX_MOD + cursor->pos) % MEM_SIZE;
		while (pos < 0)
			pos += MEM_SIZE;
		cursor->reg[cursor->op.argument[1]] =
						read_memory(game->mem, pos, DIR_SIZE);
	}
	cursor->carry = !cursor->reg[cursor->op.argument[1]];
	return (1);
}

int			operation_st(t_cursor *curs, t_game *game)
{
	int			pos;
	unsigned	utmp;

	if (curs->op.argument_type[0] == 1 && curs->op.argument_type[1] == 1)
		curs->reg[curs->op.argument[1]] = curs->reg[curs->op.argument[0]];
	else if (curs->op.argument_type[0] == 1 && curs->op.argument_type[1] == 4)
	{
		pos = (curs->op.argument[1] % IDX_MOD + curs->pos) % MEM_SIZE;
		while (pos < 0)
			pos += MEM_SIZE;
		utmp = (unsigned)curs->reg[curs->op.argument[0]];
		write_memory(game->mem, (unsigned char*)&utmp, pos,  REG_SIZE);
		if (game->win)
			set_colormap(game->win->history->color_map, curs->reg[1],
			(unsigned char*)&curs->reg[curs->op.argument[0]], pos);
	}
	else
		exit(ft_printf("ERROR: operation ST: %d %d %d as parameter types.\n",
				curs->op.argument_type[0], curs->op.argument_type[1],
				curs->op.argument_type[2]));
	return (1);
}

int			operation_add(t_cursor *curs, t_game *game)
{
	if (curs->op.argument_type[0] == 1 && curs->op.argument_type[1] == 1
		&& curs->op.argument_type[2] == 1)
		curs->reg[curs->op.argument[2]] = curs->reg[curs->op.argument[0]]
			+ curs->reg[curs->op.argument[1]];
	else
		exit(ft_printf("ERROR: operation ADD: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}
