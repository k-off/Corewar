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

#include "vm.h"

int		main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		exit(print_usage());
	if (argc > 16)
		exit(!!ft_printf("ERROR: too many arguments(%d)\n", argc - 1));
	game = (t_game*)ft_memalloc(sizeof(t_game));
	game = get_game(game);
	game_setup(game, argc, argv);
	if (game->win)
		handle_events(game);
	else
		while (play(game))
			;
	final_output(game->last_alive, game->mem, game->dump);
	return (0);
}
