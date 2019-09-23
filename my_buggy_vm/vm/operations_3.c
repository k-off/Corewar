/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			operation_zjmp(t_cursor *curs, t_game *game)
{
	int		pos;

	if (curs->carry == 1)
	{
		pos = (curs->op.argument[0] % IDX_MOD + curs->pos) % MEM_SIZE;
		while (pos < 0)
			pos += MEM_SIZE;
		curs->pos = pos;
		curs->op.op_size = 0;
	}
	return (1);
}

int			operation_ldi(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;


	if (curs->op.argument_type[1] == T_IND || curs->op.argument_type[2] != 1)
		exit(ft_printf("ERROR: operation LDI: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	args[1] = (curs->op.argument_type[1] == 2) ? curs->op.argument[1]
		: curs->reg[curs->op.argument[1]];
	pos = (curs->op.argument[0] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[0] == 1) ? curs->reg[curs->op.argument[0]]
		: read_memory(game->mem, pos, REG_SIZE);
	args[0] = (curs->op.argument_type[0] == 2) ? curs->op.argument[0]
		: args[0];
	pos = (curs->pos + (args[0] + args[1]) % IDX_MOD) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	curs->reg[curs->op.argument[2]] = read_memory(game->mem, pos, REG_SIZE);
/*	if (game->check->cur_cycle > 14090)
	{
		int cycle = game->check->cur_cycle;
		int	cur_line = curs->pos / 64;
		int	curs_pos = curs->pos % 64;
		int	read_line = pos /64;
		int	read_pos = pos % 64;
		if (read_line > 32 && read_line < 35)
			ft_printf("\tcursor: %3d load :%08x line %2d pos %2d cycle %5d\n", curs->id_c, curs->reg[curs->op.argument[2]], read_line, read_pos, cycle);
		ft_printf("");
	}*/
	return (1);
}

int			operation_sti(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;
	unsigned	utmp;

	if (game->check->cur_cycle > 14290)
		ft_printf("");
	if (curs->op.argument_type[2] == T_IND || curs->op.argument_type[0] != 1)
		exit(ft_printf("ERROR: operation STI: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	args[1] = (curs->op.argument_type[2] == 2) ? curs->op.argument[2]
		: curs->reg[curs->op.argument[2]];
	pos = (curs->op.argument[1] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[1] == 1) ? curs->reg[curs->op.argument[1]]
		: read_memory(game->mem, pos, REG_SIZE);
	args[0] = (curs->op.argument_type[1] == 2) ? curs->op.argument[1]
		: args[0];
	pos = (curs->pos + (args[0] + args[1]) % IDX_MOD) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	utmp = (unsigned)curs->reg[curs->op.argument[0]];
	write_memory(game->mem, (unsigned char*)&utmp, pos, REG_SIZE);
/*	if (game->check->cur_cycle > 14090)
	{
		int cycle = game->check->cur_cycle;
		int	cur_line = curs->pos / 64;
		int	curs_pos = curs->pos % 64;
		int	write_line = pos /64;
		int	write_pos = pos % 64;
		if (write_line > 32 && write_line < 35)
			ft_printf("\tcursor [%2d %2d]: %3d write:%08x line %2d pos %2d cycle %5d\n", curs->id_c, cur_line, curs_pos, curs->reg[curs->op.argument[0]], write_line, write_pos, cycle);
		ft_printf("");
	}*/
	return (1);
}

int			operation_fork(t_cursor *cursor, t_game *game)
{
	t_cursor	*new;
	int			pos;

	new = (t_cursor*)ft_memdup((void*)cursor, sizeof(t_cursor));
	new->next = game->cursors;
	game->cursors = new;
	ft_memset(&new->op, 0, sizeof(t_operation));
	pos = (cursor->pos + cursor->op.argument[0] % IDX_MOD) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	new->pos = pos;
	new->id_c = new->next->id_c + 1;
	return (1);
}
