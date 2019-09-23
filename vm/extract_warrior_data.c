/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_warrior_data.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/07 11:21:26 by vmulder        #+#    #+#                */
/*   Updated: 2019/09/16 14:59:23 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void				check_magic_header(int fd)
{
	unsigned			buf;
	char				*tmp;
	char				*cmp;

	read(fd, &buf, MAGIC_LENGTH);
	cmp = ft_lltoa_base(COREWAR_EXEC_MAGIC, 16, 0);
	tmp = ft_lltoa_base(buf, 16, 0);
	tmp[6] = '\0';
	ft_strrev(tmp);
	rev_per_two_char(tmp);
	if (ft_strcmp(tmp, cmp) != 0)
		error_message(4);
	free(tmp);
	free(cmp);
}

static void				extract_warrior_name_and_comment(int fd,
						char **name, char **comment)
{
	char	tmp[8];

	*name = ft_strnew(PROG_NAME_LENGTH);
	read(fd, *name, PROG_NAME_LENGTH);
	read(fd, tmp, 8);
	*comment = ft_strnew(COMMENT_LENGTH);
	read(fd, *comment, COMMENT_LENGTH);
}

static unsigned char	*extract_warrior_executable(int fd, int *i)
{
	int					read_bytes;
	unsigned char		*buf;
	char				tmp[4];

	buf = (unsigned char*)ft_memalloc(sizeof(char) * CHAMP_MAX_SIZE + 1);
	read(fd, tmp, 4);
	read_bytes = (int)read(fd, buf, 999999);
	if (read_bytes > CHAMP_MAX_SIZE || read_bytes == 0)
		error_message(6);
	else
		*i = read_bytes;
	return (buf);
}

/*
** @desc We giving a id, save if its auto gen or not.
** @param *player - the player that we assign the id nbr to.
** @param *data - struct were we save some data provided by the arg.
** @return void.
*/

static void				extract_id_nbr(t_players *player, t_cw *data)
{
	static int			warrior_id;

	if (data->custom_id)
	{
		player->id = data->custom_id;
		data->custom_id = 0;
	}
	else
	{
		warrior_id++;
		player->id = warrior_id;
		player->auto_gen_id = 1;
	}
}

/*
** @desc Extract all the info within the file by calling those functions.
** @param *argv - the argument we are going to open.
** @param *data - struct were we save some data provided by the arg.
** @param *arr - arr of players were we are going to save there data.
** @return void.
*/

void					extract_warrior_data(char *argv,
								t_players *player, t_cw *data)
{
	int	fd;

	extract_id_nbr(player, data);
	fd = open(argv, O_RDONLY);
	check_magic_header(fd);
	extract_warrior_name_and_comment(fd, &(player->name), &(player->comment));
	player->executable =
	extract_warrior_executable(fd, &(player->executable_size));
}
