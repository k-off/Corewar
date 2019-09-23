/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	remove_dead_cursors(int current_cycle, int cycles_to_die,
							t_cursor **cursors)
{
	t_cursor	*tmp;

	tmp = *cursors;
	if ((*cursors && (current_cycle - (*cursors)->last_alive >= cycles_to_die))
		|| (cycles_to_die <= 0 && current_cycle - (*cursors)->last_alive > 1))
	{
		*cursors = (*cursors)->next;
		free(tmp);
		tmp = 0;
		remove_dead_cursors(current_cycle, cycles_to_die, cursors);
	}
	if (tmp)
		remove_dead_cursors(current_cycle, cycles_to_die, &tmp->next);
}

static int	game_check(t_game *game)
{
	static t_check	*chk = 0;

	if (!chk)
	{
		chk = (t_check*)ft_memalloc(sizeof(t_check));
		chk->cur_cycle = 1;
		chk->checks_performed = 0;
		chk->cycles_to_die = CYCLE_TO_DIE;
		chk->lives_performed = 0;
		chk->next_check = chk->cycles_to_die;
	}
	chk->cur_cycle++;
	if (chk->cur_cycle == chk->next_check)
	{
		remove_dead_cursors(chk->cur_cycle, chk->cycles_to_die, &game->cursors);
		if (chk->lives_performed > 20 || chk->checks_performed > 9)
			chk->cycles_to_die -= CYCLE_DELTA;
		if (chk->lives_performed > 20 || chk->checks_performed > 9)
			chk->checks_performed = 0;
		chk->lives_performed = 0;
		chk->checks_performed++;
		chk->next_check += chk->cycles_to_die;
	}
	game->check = chk;
	return ((game->cursors == 0 || chk->cycles_to_die <= 0) ? 0 : 1);
}

static void	execute_operation(t_cursor *cursor, t_game *game)
{
	int (*operations_array[18])(t_cursor *cursor, t_game *game) =
		{NULL, operation_live, operation_ld, operation_st, operation_add,
		operation_sub, operation_and, operation_or, operation_xor,
		operation_zjmp, operation_ldi, operation_sti, operation_fork,
		operation_lld, operation_lldi, operation_lfork, operation_aff, NULL};

	if (get_operation(cursor, game, 1))
	{
		operations_array[cursor->op.opcode](cursor, game);
/*		if (game->check->cur_cycle >= 13275 && cursor->id_c == 100)
		{
			t_cursor *tmp = game->cursors;
			ft_printf("\n******************************************************\n");
			while (tmp)
			{
				if ((game->check->cur_cycle + tmp->wait > 14290 && game->check->cur_cycle + tmp->wait < 14310) && (tmp->op.opcode == 11 || tmp->op.opcode == 2))
				{
				ft_printf("\nCursor %d current cycle %d wait %d execute %d\n", tmp->id_c, game->check->cur_cycle, tmp->wait, game->check->cur_cycle + tmp->wait);
				ft_printf("\tPos:%d\n", tmp->pos);
				ft_printf("\tOp:%d\n", tmp->op.opcode);
				ft_printf("\tArgs: %5d %5d %5d\n", tmp->op.argument[0], tmp->op.argument[1], tmp->op.argument[2]);
				ft_printf("\tType: %5d %5d %5d\n", tmp->op.argument_type[0], tmp->op.argument_type[1], tmp->op.argument_type[2]);
				int	z = 1;
				while (z < 17)
				{
					ft_printf("\t%d", tmp->reg[z]);
					z++;
				}
				}
				tmp = tmp->next;
			}
		}*/
	}
}

static void	cursor_check(t_game *game)
{
	t_cursor	*current;

	current = game->cursors;
	while (current)
	{
		if (current->wait == 0)
			get_operation(current, game, 0);
		if (current->wait > 0)
			current->wait--;
		if (current->wait == 0)
		{
			if (game->check->cur_cycle == 6727 && current->id_c > 6 && current->id_c < 10)
				ft_printf("");
			execute_operation(current, game);
			current->pos = (current->pos + current->op.op_size) % MEM_SIZE;
			ft_memset(&current->op, 0, sizeof(t_operation));
		}
/*	if (game->check->cur_cycle == 6726)
		{
			int cycle = game->check->cur_cycle;
			int	cur_line = current->pos / 64;
			int	curs_pos = current->pos % 64;
			if (cur_line > 14 && cur_line < 17)
				ft_printf("\tcursor: %3d line %02d\tpos %2d cycle:%5d\n", current->id_c, cur_line, curs_pos, cycle);

		}*/
		current = current->next;
	}
	if (game->check->cur_cycle >= game->dump_cycle && game->dump)
	{
		ft_printf("AFTER CYCLE %5d:\n", game->check->cur_cycle);
		
		int		cursor_count = 0;
		t_cursor *tmp;
		tmp = game->cursors;
		while (tmp)
		{
//			if ((tmp->pos / 64 > 7 && tmp->pos / 64 < 9) || (tmp->pos / 64 > 7 && tmp->pos / 64 < 9))
//			{
				ft_printf("\tNbr:%3d\tline:%2d\tpos:%d\top:%2d\n", tmp->id_c, tmp->pos / 64, tmp->pos % 64, tmp->op.opcode);
//			}
			cursor_count++;
			tmp= tmp->next;
		}
		ft_printf("Cursors: %d\n", cursor_count);

		final_output(game->players, game->mem, game->dump);
//		ft_printf("");
	}
}

int			play(t_game *game)
{
	if (game->cursors == NULL)
		return (0);
	if (game_check(game) == 0)
		return (0);
	cursor_check(game);
//	if (game->win)
//		save_history(game);
	return (1);
}
