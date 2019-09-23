/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	bitwise_ops(int *args, int *dst, int size, int flag)
{
	if (flag == 1)
		*dst = (args[0] & args[1]);
	else if (flag == 2)
		*dst = (args[0] | args[1]);
	else if (flag == 3)
		*dst = (args[0] ^ args[1]);
}

int			operation_sub(t_cursor *curs, t_game *game)
{
	if (curs->op.argument_type[0] == 1 && curs->op.argument_type[1] == 1
		&& curs->op.argument_type[2] == 1)
		curs->reg[curs->op.argument[2]] = curs->reg[curs->op.argument[0]]
		- curs->reg[curs->op.argument[1]];
	else
		exit(ft_printf("ERROR: operation SUB: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}

int			operation_and(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;

	if (curs->op.argument_type[2] != 1)
		exit(ft_printf("ERROR: operation AND: %d %d %d as parameter types.\n",
				curs->op.argument_type[0], curs->op.argument_type[1],
				curs->op.argument_type[2]));
	args[0] = (curs->op.argument_type[0] == 1) ? curs->reg[curs->op.argument[0]]
		: curs->op.argument[0];
	args[1] = (curs->op.argument_type[1] == 1) ? curs->reg[curs->op.argument[1]]
		: curs->op.argument[1];
	pos = (curs->op.argument[0] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[0] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[0];
	pos = (curs->op.argument[1] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[1] = (curs->op.argument_type[1] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[1];
	bitwise_ops(args, &curs->reg[curs->op.argument[2]], REG_SIZE * 8, 1);
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}

int			operation_or(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;
	
	if (curs->op.argument_type[2] != 1)
		exit(ft_printf("ERROR: operation OR: %d %d %d as parameter types.\n",
			curs->op.argument_type[0], curs->op.argument_type[1],
			curs->op.argument_type[2]));
	args[0] = (curs->op.argument_type[0] == 1) ? curs->reg[curs->op.argument[0]]
		: curs->op.argument[0];
	args[1] = (curs->op.argument_type[1] == 1) ? curs->reg[curs->op.argument[1]]
		: curs->op.argument[1];
	pos = (curs->op.argument[0] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[0] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[0];
	pos = (curs->op.argument[1] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[1] = (curs->op.argument_type[1] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[1];
	bitwise_ops(args, &curs->reg[curs->op.argument[2]], REG_SIZE * 8, 2);
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}

int			operation_xor(t_cursor *curs, t_game *game)
{
	int		args[2];
	int		pos;
	
	if (curs->op.argument_type[2] != 1)
		exit(ft_printf("ERROR: operation XOR: %d %d %d as parameter types.\n",
				curs->op.argument_type[0], curs->op.argument_type[1],
				curs->op.argument_type[2]));
	args[0] = (curs->op.argument_type[0] == 1) ? curs->reg[curs->op.argument[0]]
		: curs->op.argument[0];
	args[1] = (curs->op.argument_type[1] == 1) ? curs->reg[curs->op.argument[1]]
		: curs->op.argument[1];
	pos = (curs->op.argument[0] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[0] = (curs->op.argument_type[0] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[0];
	pos = (curs->op.argument[1] % IDX_MOD + curs->pos) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	args[1] = (curs->op.argument_type[1] == 4) ?
		read_memory(game->mem, pos, REG_SIZE) : args[1];
	bitwise_ops(args, &curs->reg[curs->op.argument[2]], REG_SIZE * 8, 3);
	curs->carry = !curs->reg[curs->op.argument[2]];
	return (1);
}
