/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_setup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			board_setup(t_game *game)
{
	t_player	*plr;

	plr = game->players;
	ft_printf("Introducing contestants...\n");
	while (plr)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			plr->id_p, plr->size, plr->name, plr->comment);
		ft_memcpy(&game->mem[plr->pos], plr->exe, plr->size);
		if (game->win)
			ft_memset(&game->win->history->color_map[plr->pos],
				PLAYER_CLR[plr->id_p], plr->size);
		game->last_alive = plr;
		plr = plr->next;
	}
}

static void		set_dump(t_game *gm, int ac, char **av, int *arg_nr)
{
	gm->dump = (ft_strcmp(av[*arg_nr], "-d") == 0) ? 64 : 32;
	(*arg_nr)++;
	if (av[*arg_nr] == NULL)
		exit(ft_printf("ERROR: no value was provided for the flag '-dump'\n"));
	if (ft_strlen(av[*arg_nr]) > 10 || !ft_str_is_numeric(av[*arg_nr]))
		exit(ft_printf("ERROR: value for the flag '-dump' is invalid\n"));
	gm->dump_cycle = ft_atoi(av[*arg_nr]);
	if (gm->dump_cycle < 1 || gm->dump_cycle > 999999999)
		exit(ft_printf("ERROR: value for the flag '-dump' is out of range\n"));
	
}

static void		get_header(t_player *pl, int fd, char *fname)
{
	unsigned char	s[COMMENT_LENGTH + PROG_NAME_LENGTH + 16];
	size_t			ret;

	ret = read(fd, s, 4);
	if (ret < MAGIC_LENGTH || get_number(s, MAGIC_LENGTH) != COREWAR_EXEC_MAGIC)
		exit(!!ft_printf("ERROR: file '%s' has wrong signature\n", fname));
	ft_bzero(s, COMMENT_LENGTH + PROG_NAME_LENGTH + 16);
	ret = read(fd, s, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		exit(!!ft_printf("ERROR: file '%s' is too small\n", fname));
	pl->name = ft_memdup(s, PROG_NAME_LENGTH + 1);
	ret = read(fd, s, sizeof(int) * 2);
	if (ret < sizeof(int) * 2 || ((int*)s)[0] != 0)
		exit(!!ft_printf("ERROR: file '%s' is corrupt\n", fname));
	pl->size = (int)get_number(&s[4], sizeof(int));
	if (pl->size > CHAMP_MAX_SIZE)
		exit(!!ft_printf("ERROR: player '%s' is too big\n", pl->name));
	ft_bzero(s, COMMENT_LENGTH + PROG_NAME_LENGTH + 16);
	ret = read(fd, s, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
		exit(!!ft_printf("ERROR: file being read is too small\n"));
	pl->comment = ft_memdup(s, COMMENT_LENGTH + 1);
	ret = read(fd, s, sizeof(int));
	if (ret < sizeof(int) || ((int*)s)[0] != 0)
		exit(!!ft_printf("ERROR: file being read is corrupt\n"));
}

static int		set_player(t_game *game, int custom, int total, char *filename)
{
	int			fd;
	t_player	*pl;
	t_player	*tmp;

	if ((custom < 1 || custom > 4) && custom != 'z')
		exit(!!ft_printf("ERROR: -n %d is out of valid range (1-4)\n", custom));
	fd = open(filename, O_RDONLY);
	if (fd < 3)
		exit(!!ft_printf("ERROR: file '%s' couldn't be read\n", filename));
	pl = (t_player*)ft_memalloc(sizeof(t_player));
	pl->id_custom = (custom == 'z') ? 0 : custom;
	tmp = game->players;
	while (tmp != 0 && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp == NULL)
		game->players = pl;
	else
		tmp->next = pl;
	get_header(pl, fd, filename);
	pl->exe = (unsigned char*)ft_memalloc(pl->size + 2);
	if (read(fd, pl->exe, pl->size + 1) != pl->size)
		exit(!!ft_printf("ERROR: file '%s' is corrupt\n", filename));
	close(fd);
	return (1);
}

void			game_setup(t_game *gm, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-n") && ft_str_is_numeric(av[i + 1])
			&& i + 1 < ac)
		{
			gm->plr_qty += set_player(gm, ft_atoi(av[i + 1]), ac, av[i + 2]);
			i += 2;
		}
		else if (!ft_strcmp(av[i], "-n") && !ft_str_is_numeric(av[i + 1]))
			exit(!!ft_printf("ERROR: %s is invalid for -n flag\n", av[i + 1]));
		else if (!ft_strcmp(av[i], "-d") || !ft_strcmp(av[i], "-dump"))
			set_dump(gm, ac, av, &i);
		else if (!ft_strcmp(av[i], "-v"))
			gm->win = get_win(SIZE_X, SIZE_Y, "COREWAR\0");
		else
			gm->plr_qty += set_player(gm, 'z', ac, av[i]);
		i++;
	}
	check_players(&gm->players, &gm->cursors, gm->plr_qty);
}
