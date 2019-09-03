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

#include "../includes/disassembler.h"

/*
** @desc	return string name corresponding to the c instruction code
** @param	char	c			- intruction code
** @return	char	*name		- name of the instruction
*/

static char			*set_name(unsigned c)
{
	static char **names = 0;

	if (names == 0)
	{
		names = (char**)ft_memalloc(sizeof(char*) * 18);
		names[0] = "wrong \0";
		names[1] = "live \0";
		names[2] = "ld \0";
		names[3] = "st \0";
		names[4] = "add \0";
		names[5] = "sub \0";
		names[6] = "and \0";
		names[7] = "or \0";
		names[8] = "xor \0";
		names[9] = "zjmp \0";
		names[10] = "ldi \0";
		names[11] = "sti \0";
		names[12] = "fork \0";
		names[13] = "lld \0";
		names[14] = "lldi \0";
		names[15] = "lfork \0";
		names[16] = "aff \0";
	}
	return (ft_strdup(names[c]));
}

/*
** @desc	allocate a new operation struct and append to the end of linked list
** @param	t_data *data		- all data struct
** @return	t_operation	*op		- pointer to the set operation
*/

static t_operation	*set_new_operation(t_data *data)
{
	t_operation *op;

	if (data->op == NULL)
	{
		data->op = (t_operation*)ft_memalloc(sizeof(t_operation));
		op = data->op;
	}
	else
	{
		op = data->op;
		while (op->next != NULL)
			op = op->next;
		op->next = (t_operation*)ft_memalloc(sizeof(t_operation));
		op = op->next;
	}
	return (op);
}

/*
** @desc	some weird shit. checks type of the current argument based on octet,
** @desc	decides how many bytes to read (size),
** @desc	converts read data into number (value),
** @desc	converts number into string (tmp),
** @desc	appends the string to the current arg (args[arg_nr])
** @param	char		**args		- array of arguments
** @param	int			arg_nr		- number of current argument
** @param	unsigned	octet		- octet of the current operation
** @param	t_operation	*op			- pointer to the set operation
** @return	int			c			- bytes read
*/

static int			get_value(char **args, int arg_nr, unsigned octet, int c)
{
	unsigned char	s[4];
	char			**tmp;
	int				value;
	int				type;
	int				size;

	type = (octet == 0) ? 2 : ((octet >> (4 - arg_nr * 2)) & 3);
	size = (type == 2) ? (T_DIR_SIZE[c]) : 2;
	size = (type == 1) ? 1 : size;
	c = (int)read(get_data(NULL)->fd_r, s, size);
	if (c != size && (int)ft_strlen((char*)s) != size)
		exit(!!ft_printf("ERROR: couldn't read argument value\n"));
	value = get_number(s, size);
	tmp = (char**)ft_memalloc(sizeof(char*) * 3);
	tmp[1] = ft_itoa(value);
	tmp[0] = args[arg_nr];
	if (ft_strlen(args[arg_nr]) == 0)
		args[arg_nr] = ft_strdup(tmp[1]);
	else
		args[arg_nr] = ft_strjoin(tmp[0], tmp[1]);
	free_str_arr(NULL, &tmp, 0);
	return (c);
}

/*
** @desc	allocate and iterate through arguments of current operation
** @param	t_operation	*op			- pointer to the current operation
** @param	unsigned	oct			- octet of the current operation
** @param	int			arg_qt		- amount of arguments of current operation
** @param	int			opc			- current operation code
** @return	int			size		- amount of bytes read from file
*/

static int			get_args(t_operation *op, unsigned oct, int arg_qt, int opc)
{
	int		i;
	char	*tmp;
	int		size;

	op->args = (char**)ft_memalloc(sizeof(char*) * (arg_qt + 1));
	i = 0;
	size = 0;
	while (i < arg_qt)
	{
		if (oct != 0 && ((oct >> (4 - i * 2)) & 3) == 1)
			op->args[i] = ft_strdup("r");
		else if ((oct != 0 && ((oct >> (4 - i * 2)) & 3) == 2) || oct == 0)
			op->args[i] = ft_strdup("%");
		else
			op->args[i] = ft_strdup("");
		size += get_value(op->args, i, oct, opc);
		if (i > 0)
		{
			tmp = ft_strjoin(",", op->args[i]);
			free_str_arr(&(op->args[i]), NULL, 1);
			op->args[i] = tmp;
		}
		i++;
	}
	return (size);
}

/*
** @desc	allocate and set values for operation struct
** @param	t_data		*data		- pointer to the all-data struct
** @param	int			opcod		- current operation code
** @param	int			*data_size	- octet of the current operation
** @param	int			arg_qt		- amount of arguments of current operation
** @return							- void
*/

void				get_instruction(t_data *data, int opcod, int *data_size)
{
	t_operation			*op;
	size_t				i;
	unsigned char		s;
	size_t				ret;

	op = set_new_operation(data);
	if (op == NULL)
		exit(!!ft_printf("ERROR: operation struct wasn't allocated\n"));
	op->name = set_name(opcod);
	i = 0;
	if (OCTAL[opcod] != 0)
	{
		ret = read(data->fd_r, &s, 1);
		*data_size -= ret;
		*data_size -= get_args(op, (unsigned)(s >> 2), ARGS_QTY[opcod], opcod);
	}
	else
		*data_size -= get_args(op, 0, ARGS_QTY[opcod], opcod);
}
