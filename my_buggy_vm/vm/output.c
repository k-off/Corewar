/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	final_output(t_player *player, unsigned char *mem, int wide)
{
	int		i;
	char	tmp[4];
	char	*hex;

	wide = 64; // delete later
	ft_printf("Contestant %d, \"%s\", has won !\n", player->id_p, player->name);
	ft_printf("Current cycle: %d\n\n", get_game(NULL)->check->cur_cycle);
	if (wide == 0)
		exit(0);
	i = 0;
	hex = "0123456789abcdef\0";
	tmp[2] = ' ';
	tmp[3] = 0;
	while (i < MEM_SIZE/* * 0.6*/)
	{
		if (i == 0)
			ft_printf("0x%04x : ", i);
		if (i > 0 && i % wide == 0)
			ft_printf("\n%#.4x : ", i);
		tmp[0] = hex[mem[i] / 16];
		tmp[1] = hex[mem[i] % 16];
		ft_printf("%s", tmp);
		i++;
	}
	ft_printf("\n");
//	exit (0);
}

/*
** @desc	print players ids, sizes, names and comments at the game start
** @param	t_player	*players	- pointer to the linked list of players
** @return							- void
*/

void	introduce_players(t_player *players)
{
	t_player *tmp;

	tmp = players;
	ft_printf("Introducing contestants...\n");
	while (tmp)
	{
		ft_printf("* Player %d, weighing %d bytes, ", tmp->id_p, tmp->size);
		if (tmp->name)
			ft_printf("\"%s\" ", tmp->name);
		if (tmp->comment)
			ft_printf("(\"%s\")", tmp->comment);
		ft_printf("!\n");
		tmp = tmp->next;
	}
}

/*
** @desc	print usage
** @return	int			- 1
*/

int		print_usage(void)
{
	ft_printf("usage:\t./vm player1 [-n number_modifier1 ... ");
	ft_printf("playerN.cor [-n number_modifierN]]\n");
	ft_printf("\tflags:\t-v\tenable visualizer\n");
	ft_printf("\t\t-n\tmodify player's number\n");
	ft_printf("\t\t-d\tprint out 64-byte wide memory dump after game ends\n");
	ft_printf("\t\t-dump\tprint out 32-byte wide memory dump after game\n\n");
	ft_printf("\t\tvisualizer:\n");
	ft_printf("\t\tspace\t\t- switch between normal and debug modes\n");
	ft_printf("\t\t<\t\t- one cycle back in the debug mode\n");
	ft_printf("\t\t>\t\t- one cycle forward in the debug mode\n");
	ft_printf("\t\tleft arrow\t- display information of previous cursor\n");
	ft_printf("\t\tright arrow\t- display information of next cursor\n");
	return (1);
}
