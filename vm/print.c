/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/18 14:16:34 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/18 14:16:36 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Print winner based on which player ID was reported 'live' last.
** @param t_players **players - array of players structures
** @param int winner_id - ID of winner
** @return void
*/

void	print_winner(t_players **players, int winner_id)
{
	int	i;

	i = 0;
	while (players[i] != NULL && i < 4)
	{
		if (players[i]->id == winner_id)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n",
			players[i]->id, players[i]->name);
			if (get_visual(0) != 1)
				exit(1);
			break ;
		}
		i++;
	}
}

void	print_arena(unsigned char *arena)
{
	int	i;
	int	address;

	i = 0;
	address = 0;
	while (i < 4096)
	{
		if (i != 0 && i % 32 == 0)
			ft_printf("%#06x : ", address);
		else if (i == 0)
			ft_printf("0x0000 : ");
		ft_printf("%02hhx ", arena[i]);
		if (i != 0 && (i + 1) % 32 == 0)
		{
			ft_printf("\n");
			address = address + 32;
		}
		i++;
	}
}

void	print_carriages(t_carriage **carriages)
{
	int	i;

	i = 0;
	while (carriages[i] != NULL)
	{
		ft_printf("----- CARRIAGE %d -----\n", carriages[i]->id);
		ft_printf("Current position : %d\n", carriages[i]->current_position);
		ft_printf("Current opcode : %d\n", carriages[i]->current_opcode);
		ft_printf("Cycles before execution : %d\n",
		carriages[i]->cycles_before_execution);
		i++;
	}
}

void	print_carriage(t_carriage *carriages)
{
	ft_printf("$$----- CARRIAGE %d -----$$\n", carriages->id);
	ft_printf("Current position : %d\n", carriages->current_position);
	ft_printf("Current opcode : %d\n", carriages->current_opcode);
	ft_printf("Cycles before execution : %d\n",
	carriages->cycles_before_execution);
	ft_printf("\n");
}
