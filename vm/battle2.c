/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   battle2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/15 14:52:07 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/09/15 14:52:09 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		battle_execute(void)
{
	static int		cycles_after_check;
	t_carriage		**carriages;

	carriages = save_carriages(NULL);
	if (carriages[0] != NULL)
	{
		number_of_cycles(1);
		cycles_after_check++;
		battle_execute_assist(carriages);
		if (cycles_after_check == cycles_to_die(JUST_RETURN) ||
		cycles_to_die(JUST_RETURN) <= 0)
		{
			number_of_checks(1);
			remove_dead_carriages(carriages, number_of_cycles(JUST_RETURN),
			cycles_to_die(JUST_RETURN));
			battle_execute_decrement();
			number_of_live_performed(-1);
			cycles_after_check = 0;
		}
		return (1);
	}
	return (0);
}

void	battle_execute_assist(t_carriage **carriages)
{
	int				i;
	int				opcode;
	unsigned char	*ptr;

	i = 0;
	opcode = -1;
	ptr = 0;
	get_current_cycle(1);
	while (carriages[i] != NULL)
	{
		if (carriages[i]->cycles_before_execution - 1 == 0)
			opcode = carriages[i]->current_opcode;
		carriage_command_hub(carriages[i]);
		if (opcode == 12 || opcode == 15)
		{
			i++;
			opcode = -1;
		}
		i++;
	}
	if (get_pause(0) == 2 && get_visual(0) == 1)
		get_pause(49);
}

void	battle_execute_decrement(void)
{
	if (number_of_checks(JUST_RETURN) == MAX_CHECKS ||
	number_of_live_performed(JUST_RETURN) >= NBR_LIVE)
	{
		cycles_to_die(1);
		number_of_checks(-1);
	}
}
