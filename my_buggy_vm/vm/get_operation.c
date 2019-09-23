/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_operation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_values(t_operation *op, int type, int nr)
{
	int		result;

	result = 1;
	if (type == T_REG)
		result = (op->argument[nr] < 17 && op->argument[nr] > 0) ? 1 : 0;
	if (type == T_REG)
		op->argument_size[nr] = 1;
	else if (type == T_IND)
		op->argument_size[nr] = 2;
	else if (type == T_DIR)
		op->argument_size[nr] = T_DIR_SIZE[op->opcode];
	return (result);
}

static void	read_arguments(t_operation *op, int pos, unsigned char *mem, int *r)
{
	int		i;
	

	i = 0;
	while (i < ARGS_QTY[op->opcode])
	{
		if (op->argument_type[i] == T_REG)
			op->argument[i] = read_memory(mem, pos + op->op_size, 1);
		else if (op->argument_type[i] == T_IND)
			op->argument[i] = read_memory(mem, pos + op->op_size, 2);
		else if (op->argument_type[i] == T_DIR)
			op->argument[i] = read_memory(mem, pos + op->op_size,
				T_DIR_SIZE[op->opcode]);
		*r *= check_values(op, op->argument_type[i], i);
		op->op_size += op->argument_size[i];
		i++;
	}
}

static int check_octet(t_operation *op, int pos, unsigned char *mem)
{
	int		i;
	int		alwd_t;
	int		cur_t;
	int		res;

	i = ARGS_QTY[op->opcode];
	alwd_t = ARGS_TYPE[op->opcode];
	res = 1;
	while (i > 0)
	{
		i--;
		cur_t = ((op->octet & 3) == 3) ? T_IND : (op->octet & 3);
		if ((cur_t & (alwd_t % 10)) == 0 && cur_t != 0 && alwd_t % 10 != 0)
			res = 0;
		op->argument_type[i] = cur_t;
		op->octet = (op->octet >> 2);
		alwd_t /= 10;
	}
	read_arguments(op, pos, mem, &res);
	return (res);
}

static int	get_arguments(t_operation *op, int pos, unsigned char *mem)
{
	unsigned char i;

	i = UCHAR_MAX;
	if (OCTAL[op->opcode])
	{
		op->octet = read_memory(mem, pos + 1, 1) >>
					((4 - ARGS_QTY[op->opcode]) * 2);
		op->op_size++;
		return (check_octet(op, pos, mem));
	}
	else
	{
		op->argument_size[0] = T_DIR_SIZE[op->opcode];
		op->argument_type[0] = 2;
		op->argument[0] = read_memory(mem, pos + 1, T_DIR_SIZE[op->opcode]);
		op->op_size += op->argument_size[0];
		return (1);
	}
}

int			get_operation(t_cursor *cursor, t_game *game, int flag)
{
	cursor->op.op_size = 1;
	if (flag == 0)
	{
		cursor->op.opcode = (int)game->mem[cursor->pos];
		if (cursor->op.opcode > 0 && cursor->op.opcode < 17)
		{
			cursor->wait = WAIT_TIME[cursor->op.opcode];
			return (1);
		}
		else
			return (0);
	}
	else if (flag == 1 && (cursor->op.opcode < 1 || cursor->op.opcode > 16))
	{
		cursor->op.opcode = 0;
		return (0);
	}
	else
		return (get_arguments(&cursor->op, cursor->pos, game->mem));
}
