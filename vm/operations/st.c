/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:28 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:23:29 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'st' command is executed by carriage,
** @desc then carriage_st_hub extracts information
** @desc about the arguments and determines whether
** @desc or not all of them are registers.
** @desc extract_types_2 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If add has received valid 2 registers, it extracts
** @desc argument values and sends them to carriage_st function,
** @desc which actually executes the command. Thus carriage_st_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_st_hub(t_carriage *carriage, unsigned char *arena)
{
	int		arg1;
	int		arg2;
	int		temp;
	t_types	*types;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	types = extract_types_2(arena[(carriage->current_position + 1) % 4096]);
	if (types->type1 == 1 && (types->type2 == 1 || types->type2 == 3))
	{
		arg1 = extract_1_byte(carriage->current_position + 2);
		if (!(arg1 >= 1 && arg1 <= 16) ||
		carriage_st_hub_assist_1(carriage, types, &arg2, &temp) == 0)
		{
			carriage_jump(carriage);
			free(types);
			return ;
		}
		if (types->type2 == 1)
			carriage_st(carriage, arg1, arg2, -1);
		else if (types->type2 == 3)
			carriage_st(carriage, arg1, -1, arg2);
	}
	free(types);
	carriage_jump(carriage);
}

int		carriage_st_hub_assist_1(t_carriage *carriage,
		t_types *types, int *arg2, int *temp)
{
	if (types->type2 == 1)
	{
		*arg2 = extract_1_byte(carriage->current_position + 3);
		if (!(*arg2 >= 1 && *arg2 <= 16))
			return (0);
	}
	else if (types->type2 == 3)
	{
		*temp = extract_2_bytes(carriage->current_position + 3);
		*arg2 = (carriage->current_position +
		(*temp % IDX_MOD)) % 4096;
		if (*arg2 < 0)
			*arg2 = 4096 + *arg2;
	}
	return (1);
}
