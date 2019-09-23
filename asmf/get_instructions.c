/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_instructions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

static int			is_instruction_2(char *s)
{
	if (ft_strcmp(s, "fork\0") == 0)
		return (12);
	else if (ft_strcmp(s, "lld\0") == 0)
		return (13);
	else if (ft_strcmp(s, "lldi\0") == 0)
		return (14);
	else if (ft_strcmp(s, "lfork\0") == 0)
		return (15);
	else if (ft_strcmp(s, "aff\0") == 0)
		return (16);
	else
		return (0);
}

/*
** @desc	check whether the received string refers to an instruction or not
** @param	char		*s		- string
** @return	int					- true or false
*/

int					is_instruction(char *s)
{
	if (ft_strcmp(s, "live\0") == 0)
		return (1);
	else if (ft_strcmp(s, "ld\0") == 0)
		return (2);
	else if (ft_strcmp(s, "st\0") == 0)
		return (3);
	else if (ft_strcmp(s, "add\0") == 0)
		return (4);
	else if (ft_strcmp(s, "sub\0") == 0)
		return (5);
	else if (ft_strcmp(s, "and\0") == 0)
		return (6);
	else if (ft_strcmp(s, "or\0") == 0)
		return (7);
	else if (ft_strcmp(s, "xor\0") == 0)
		return (8);
	else if (ft_strcmp(s, "zjmp\0") == 0)
		return (9);
	else if (ft_strcmp(s, "ldi\0") == 0)
		return (10);
	else if (ft_strcmp(s, "sti\0") == 0)
		return (11);
	else
		return (is_instruction_2(s));
}

/*
** @desc	find and return an existing operation struct or allocate a new one
** @param	t_data		*data	- pointer to the data structure
** @param	int			inst_id	- id of current instruction
** @param	int			op_id	- unique id of the operation
** @return	t_operation *op		- pointer to the operation being set
*/

static t_operation	*set_instruction(t_data *data, int inst_id, int op_id)
{
	t_operation *op;

	op = data->op;
	while (op != NULL && op->next != NULL)
	{
		op_id++;
		op = op->next;
	}
	if (op == NULL)
	{
		data->op = (t_operation*)ft_memalloc(sizeof(t_operation));
		op = data->op;
	}
	else
	{
		op->next = (t_operation*)ft_memalloc(sizeof(t_operation));
		op_id++;
		op = op->next;
	}
	op->instruction_id = inst_id;
	op->unique_id = op_id;
	op->position = data->total_size;
	return (op);
}

/*
** @desc	calculate operations' size
** @param	t_operation *op		- pointer to the operation structure
** @return						- void
*/

static void			set_operation_size(t_operation *op)
{
	int		i;

	i = 0;
	op->size = 1;
	while (i < MAX_ARGS)
	{
		op->size += op->argument_size[i];
		i++;
	}
	op->size += (op->octet != 0);
}

/*
** @desc	convert instruction from the received array of strings
** @param	t_data		*data	- pointer to the data structure
** @param	char		**tmp	- array of strings, operation arguments
** @param	int			inst_id	- id of current instruction
** @param	int			tmp_len	- amount of received strings
** @return	int					- offset of current operation from the start of
**									champions' executable code
*/

int					get_instruction(t_data *data, char **tmp,
								int inst_id, int tmp_len)
{
	t_operation *op;

	if (inst_id == 0)
		return (0);
	if (tmp_len < 2)
		exit(!!ft_printf("ERROR: no arguments at line %d\n", data->line_qty));
	op = set_instruction(data, inst_id, 1);
	get_arguments(op, &tmp[1], tmp_len - 1, data);
	set_operation_size(op);
	data->total_size += op->size;
	return (op->position);
}
