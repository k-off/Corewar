/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/assembler.h"

/*
** @desc	compare size of operation with current arguments with previously
** @desc	calculated one
** @param	t_operation *op		- pointer to current operation structure
** @return						- void
*/

static void	check_size(t_operation *op)
{
	int	size;
	int	i;

	size = 1;
	size += (op->octet != 0);
	i = 0;
	while (i < MAX_ARGS)
	{
		if (op->argument_type[i] < 0)
			exit(!!ft_printf("ERROR: negative argument type for op. %d\n",
					op->unique_id));
		if (op->argument_type[i] == 1 &&
			(op->argument[i] < 1 || op->argument[i] > 99))
			exit(!!ft_printf("ERROR: invalid registry value for op. %d\n",
				op->unique_id));
		if (op->argument_type[i] == 1)
			size++;
		if (op->argument_type[i] == 2)
			size += T_DIR_SIZE[op->instruction_id];
		else if (op->argument_type[i] == 3)
			size += 2;
		i++;
	}
	if (size != op->size)
		exit(!!ft_printf("ERROR: wrong op. size, op. %d\n", op->unique_id));
}

/*
** @desc	search for the label used in current argument of current operation
** @param	t_operation *oper	- pointer to current operation structure
** @param	t_label		*label	- pointer to all available labels
** @param	int			arg_nr	- number of current argument
** @return						- void
*/

static void	check_labels(t_operation *oper, t_label *label, int arg_nr)
{
	t_label		*tmp;

	tmp = label;
	if ((oper->arg_is_label[arg_nr] != 0 && oper->argument_type[arg_nr] > 0) ||
		(oper->arg_is_label[arg_nr] == 0 && oper->argument_type[arg_nr] < 0))
		exit(!!ft_printf("ERROR: incompatible argument-label combination\n"));
	else if (oper->argument_type[arg_nr] < 0)
		oper->argument_type[arg_nr] = -oper->argument_type[arg_nr];
	while (tmp != NULL && tmp->unique_id != oper->arg_is_label[arg_nr])
		tmp = tmp->next;
	if (tmp == NULL)
		exit(!!ft_printf("ERROR: label %d for op.%d not found\n",
			oper->arg_is_label[arg_nr], oper->unique_id));
	if (tmp->position == -1)
		exit(!!ft_printf("ERROR: label %s not found\n", tmp->name));
	oper->argument[arg_nr] = tmp->position - oper->position;
	if (oper->argument_type[arg_nr] == 1 &&
		(oper->argument[arg_nr] > 99 || oper->argument[arg_nr] < 1))
		exit(!!ft_printf("ERROR: operation %d argument %d is reg %d - invld",
			oper->unique_id, arg_nr, oper->argument[arg_nr]));
}

/*
** @desc	check arguments of current operation
** @param	t_operation *oper	- pointer to current operation structure
** @param	t_label		*labels - pointer to all available labels
** @return						- void
*/

static void	check_arguments(t_operation *oper, t_label *labels)
{
	int		i;
	int		args_qty;
	int		allowed;

	i = MAX_ARGS;
	args_qty = ARGS_QTY[oper->instruction_id];
	allowed = ARGS_TYPES[oper->instruction_id];
	while (i > args_qty)
	{
		i--;
		if (oper->argument_type[i] != 0)
			exit(!!ft_printf("ERROR: too many arguments for instr nr %d",
				oper->unique_id));
		allowed /= 10;
	}
	while (i > 0)
	{
		i--;
		if (oper->argument_type[i] < 0 || oper->arg_is_label[i] != 0)
			check_labels(oper, labels, i);
		if ((allowed % 10) != 0 && ((allowed % 10) & (oper->argument_type[i] +
										(oper->argument_type[i] > 2))) == 0)
			exit(!!ft_printf("ERROR: invalid argument type\n"));
		allowed /= 10;
	}
}

/*
** @desc	check converted operation
** @param	t_data		*data	- pointer to data structure
** @param	t_operation *oper	- pointer to operation structure
** @return						- void
*/

static void	check_operation(t_data *data, t_operation *oper)
{
	if (oper->instruction_id > 16 || oper->instruction_id < 1)
		exit(!!ft_printf("ERROR: instr. id %d for operation nr %d is invalid\n",
			oper->instruction_id, oper->unique_id));
	if (oper->unique_id < 1)
		exit(!!ft_printf("ERROR: id for operation nr %d is invalid\n",
			oper->unique_id));
	if (oper->next && oper->unique_id - oper->next->unique_id != -1)
		exit(!!ft_printf("ERROR: operation %d enumeration sequence is wrong\n",
			oper->unique_id));
	if (oper->position >= data->total_size)
		exit(!!ft_printf("ERROR: operation nr %d position %d is above \
		total data size (%d)\n", oper->unique_id, oper->position,
		data->total_size));
	oper->octet *= OCTAL[oper->instruction_id];
}

/*
** @desc	check the converted data
** @param	t_data	*data		- pointer to data structure
** @return						- void
*/

void		check(t_data *data)
{
	t_operation		*operation;
	t_label			*labels;

	if (!data->name)
		exit(!!ft_printf("ERROR: Champ name is not set\n"));
	if (!data->comment)
		exit(!!ft_printf("ERROR: Champ comment is not set\n"));
	if (!data->op)
		exit(!!ft_printf("ERROR: Champ has no instructions\n"));
	if (ft_strlen(data->name) > PROG_NAME_LENGTH)
		exit(!!ft_printf("ERROR: Champ name len (%d) > maximum len (%d)\n",
			ft_strlen(data->name), PROG_NAME_LENGTH));
	if (ft_strlen(data->comment) > COMMENT_LENGTH)
		exit(!!ft_printf("ERROR: Champ comment len (%d) > maximum len (%d)\n",
			ft_strlen(data->comment), COMMENT_LENGTH));
	operation = data->op;
	while (operation)
	{
		check_operation(data, operation);
		labels = data->label;
		check_arguments(operation, labels);
		check_size(operation);
		operation = operation->next;
	}
}
