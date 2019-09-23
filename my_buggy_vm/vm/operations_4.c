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

int			operation_lld(t_cursor *cursor, t_game *game)
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
		pos = (cursor->op.argument[0] + cursor->pos) % MEM_SIZE;
		while (pos < 0)
			pos += MEM_SIZE;
		cursor->reg[cursor->op.argument[1]] =
		read_memory(game->mem, pos, DIR_SIZE);
	}
	cursor->carry = !cursor->reg[cursor->op.argument[1]];
	return (1);
}

int			operation_lldi(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;
	
	if (curs->op.argument_type[1] == T_IND || curs->op.argument_type[2] != 1)
		exit(ft_printf("ERROR: operation LDI: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	args[1] = (curs->op.argument_type[1] == 2) ? curs->op.argument[1]
		: curs->reg[curs->op.argument[1]];
	pos = (curs->op.argument[0] + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[0] == 1) ? curs->reg[curs->op.argument[0]]
		: read_memory(game->mem, pos, REG_SIZE);
	args[0] = (curs->op.argument_type[0] == 2) ? curs->op.argument[0]
		: args[0];
	pos = (curs->pos + (args[0] + args[1])) % MEM_SIZE;
	curs->reg[curs->op.argument[2]] = read_memory(game->mem, pos, REG_SIZE);
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}

int			operation_lfork(t_cursor *cursor, t_game *game)
{
	t_cursor	*new;
	int			pos;
	
	new = (t_cursor*)ft_memdup((void*)cursor, sizeof(t_cursor));
	new->next = game->cursors;
	game->cursors = new;
	ft_memset(&new->op, 0, sizeof(t_operation));
	pos = (cursor->pos + cursor->op.argument[0]) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	new->pos = pos;
	new->id_c = new->next->id_c + 1;
	return (1);
}

int			operation_aff(t_cursor *cursor, t_game *game)
{
	if (cursor->op.argument_type[0] != 1)
		exit(ft_printf("ERROR: operation AFF: %d %d %d as parameter types.\n",
			cursor->op.argument_type[0], 0, 0));
	ft_printf("Aff: %c\n", (char)cursor->reg[cursor->op.argument[0]]);
	return (1);
}
