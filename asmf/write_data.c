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
** @desc	write numbers in big endian to the given file descriptor
** @param	int			  fd	  - file descriptor
** @param	unsigned char *str	  - pointer to the number to be written
** @param	unsigned total_length - length of the number to be written
** @return						  - void
*/

static void	write_reverse(int fd, unsigned char *str, unsigned total_length)
{
	while (total_length > 0)
	{
		total_length--;
		write(fd, &str[total_length], 1);
	}
}

/*
** @desc	write name and comment of champion to the file with trailing zeros
** @param	int			fd		  - file descriptor
** @param	char		*str	  - string, name or comment of champion
** @param	unsigned total_length - length of the number to be written
** @return						  - void
*/

static void	write_name_comment(int fd, char *str, unsigned total_length)
{
	int		len;
	char	*zeros;

	len = (int)ft_strlen(str);
	zeros = (char*)ft_memalloc(sizeof(char) * (total_length - len + 1));
	write(fd, str, len);
	write(fd, zeros, (total_length - len));
	free_str_arr(&zeros, NULL, 1);
}

/*
** @desc	select type of number to be written based on the argument type
** @param	int			fd			- file descriptor
** @param	t_operation	*op			- pointer to the current operation
** @param	int			arg_nr		- number of the current argument
** @return							- void
*/

static void	select_type(int fd, t_operation *op, int arg_nr)
{
	unsigned char	c;
	unsigned short	s;
	unsigned int	i;

	if (op->argument_type[arg_nr] == 1)
	{
		c = (unsigned char)op->argument[arg_nr];
		write_reverse(fd, (unsigned char*)(&c), sizeof(c));
	}
	else if (op->argument_type[arg_nr] == 2
		&& T_DIR_SIZE[op->instruction_id] == 4)
	{
		i = (unsigned int)op->argument[arg_nr];
		write_reverse(fd, (unsigned char*)(&i), sizeof(i));
	}
	else
	{
		s = (unsigned short)op->argument[arg_nr];
		write_reverse(fd, (unsigned char*)(&s), sizeof(s));
	}
}

/*
** @desc	write current operation, it's octet and iterate arguments
** @param	int			fd			- file descriptor
** @param	t_operation	*op			- pointer to the current operation
** @return							- void
*/

static void	write_operation(int fd, t_operation *op)
{
	unsigned char	c;
	int				j;

	c = (unsigned char)op->instruction_id;
	write_reverse(fd, (unsigned char*)(&c), sizeof(c));
	if (op->octet != 0)
	{
		c = (unsigned char)op->octet;
		write_reverse(fd, (unsigned char*)(&c), sizeof(c));
	}
	j = 0;
	while (j < ARGS_QTY[op->instruction_id])
	{
		select_type(fd, op, j);
		j++;
	}
}

/*
** @desc	write champion header and iterate through it's operations
** @param	t_data		*data		- pointer to the data structure
** @return							- void
*/

void		write_data(t_data *data)
{
	int			magic;
	int			zero;
	t_operation	*op;

	magic = COREWAR_EXEC_MAGIC;
	zero = 0;
	write_reverse(data->fd_w, (unsigned char*)(&magic), sizeof(int));
	write_name_comment(data->fd_w, data->name, PROG_NAME_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero), sizeof(int));
	write_reverse(data->fd_w, (unsigned char*)(&data->total_size), sizeof(int));
	write_name_comment(data->fd_w, data->comment, COMMENT_LENGTH);
	write(data->fd_w, (unsigned char*)(&zero), sizeof(int));
	op = data->op;
	while (op != NULL)
	{
		write_operation(data->fd_w, op);
		op = op->next;
	}
}
