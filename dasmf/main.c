/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/disassembler.h"

/*
** @desc	set the name of the ouput file
** @param	char	*s			- string, name of the input file
** @return						- void
*/

static char	*set_output_name(char *s)
{
	char	*name;
	char	**tmp;

	if (ft_strlen(s) < 1)
		exit(!!ft_printf("ERROR: output file name not defined\n"));
	tmp = ft_strsplit(s, '.');
	if (ft_strlen(tmp[0]) > 0)
		name = ft_strjoin(tmp[0], ".s");
	else
		name = ft_strdup(".s");
	if (ft_strlen(name) < 1)
		exit(!!ft_printf("ERROR: output file name couldn't be set\n"));
	free_str_arr(NULL, &tmp, 0);
	return (name);
}

/*
** @desc	get name and comment, check magic and zero bytes
** @param	t_data *data		- pointer to data structure
** @return						- void
*/

static void	get_header(t_data *data)
{
	unsigned char	s[COMMENT_LENGTH + 1];
	size_t			ret;

	ret = read(data->fd_r, (void*)s, 4);
	if (ret < MAGIC_LENGTH || get_number(s, MAGIC_LENGTH) != COREWAR_EXEC_MAGIC)
		exit(ft_printf("ERROR: file being read has wrong signature\n"));
	ft_bzero((void*)s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		exit(!!ft_printf("ERROR: file being read is too small\n"));
	data->name = ft_memdup(s, PROG_NAME_LENGTH + 1);
	ret = read(data->fd_r, s, 8);
	if (ret < 8 || ((int*)s)[0] != 0)
		exit(!!ft_printf("ERROR: file being read is corrupt\n"));
	data->total_size = (int)get_number(&s[4], sizeof(int));
	ft_bzero((void*)s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
		exit(!!ft_printf("ERROR: file being read is too small\n"));
	data->comment = ft_memdup(s, COMMENT_LENGTH + 1);
	ret = read(data->fd_r, s, 4);
	if (ret < 4 || ((int*)s)[0] != 0)
		exit(!!ft_printf("ERROR: file being read is corrupt\n"));
}

/*
** @desc	main conversion loop, iterate while smth. is read
** @param	t_data *data		- pointer to data structure
** @return						- void
*/

static void	conversion_loop(t_data *data)
{
	unsigned char	s;
	int				data_size;
	size_t			ret;

	get_header(data);
	data_size = data->total_size;
	ret = 1;
	while (ret > 0)
	{
		s = 0;
		ret = read(data->fd_r, &s, 1);
		data_size -= ret;
		if (ret < 1)
			break ;
		if (s < 1 || s > 16)
			exit(!!ft_printf("ERROR: %d is not a valid instruction\n", s));
		get_instruction(data, (int)s, &data_size);
	}
	if (data_size != 0)
		exit(!!ft_printf("ERROR: champions' executable code size is wrong\n"));
}

/*
** @desc	write data to the .s file
** @param	int		fd			- file descriptor of the written file
** @param	char	*name		- name of champion
** @param	char	*comment	- comment of champion
** @param	t_operation *op		- pointer to linked list of operations
** @return						- void
*/

static void	write_data(int fd, char *name, char *comment, t_operation *op)
{
	write(fd, ".name \"", 7);
	write(fd, name, ft_strlen(name));
	write(fd, "\"\n.comment \"", 12);
	write(fd, comment, ft_strlen(comment));
	write(fd, "\"\n\n", 3);
	while (op)
	{
		write(fd, op->name, ft_strlen(op->name));
		while (op->args[0])
		{
			write(fd, op->args[0], ft_strlen(op->args[0]));
			(op->args)++;
		}
		write(fd, "\n", 1);
		op = op->next;
	}
}

/*
** @desc	get file names as arguments and send last argument to conversion
** @param	int argc			- amount of arguments
** @param	char **s argv		- array of string arguments
** @return						- 0
*/

int			main(int argc, char **argv)
{
	char	*file_name;
	t_data	*data;

	if (argc != 2)
		exit(!!ft_printf("usage: ./dasm file_name\n"));
	data = (t_data*)ft_memalloc(sizeof(t_data));
	get_data(data);
	data->fd_r = open(argv[argc - 1], O_RDONLY);
	if (data->fd_r < 3)
		exit(!!ft_printf("ERROR: file %s couldn't be read\n", argv[argc - 1]));
	conversion_loop(data);
	file_name = set_output_name(argv[argc - 1]);
	data->fd_w = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (data->fd_w < 3)
		exit(!!ft_printf("ERROR: file %s was not created\n", argv[argc - 1]));
	write_data(data->fd_w, data->name, data->comment, data->op);
	close(data->fd_w);
	close(data->fd_r);
	return (0);
}
