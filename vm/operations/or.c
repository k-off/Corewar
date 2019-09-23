/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:50 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:23:51 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'or' command is executed by carriage,
** @desc then carriage_add_hub extracts information
** @desc about the arguments and determines their types
** @desc extract_types_3 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If and has received valid 3 arguments, it extracts
** @desc argument values and sends them to carriage_or function,
** @desc which actually executes the command. Thus carriage_or_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_or_hub(t_carriage *carriage, unsigned char *arena)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		temp;
	t_types	*types;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	types = extract_types_3(arena[(carriage->current_position + 1) % 4096]);
	if (types->type3 == 1 && types->type1 != 0 && types->type2 != 0)
	{
		arg3 = extract_1_byte(carriage->current_position + carriage->jump - 1);
		if (!valid_register(arg3) ||
		carriage_or_hub_assist_1(carriage, types, &arg1, &temp) == 0)
		{
			carriage_jump(carriage);
			free(types);
			return ;
		}
		if (carriage_or_hub2(carriage, types, &arg2, &temp) == 0)
			return ;
		carriage_or(carriage, arg1, arg2, arg3);
	}
	free(types);
	carriage_jump(carriage);
}

int		carriage_or_hub2(t_carriage *carriage,
		t_types *types, int *arg2, int *temp)
{
	if (types->type2 == 1)
	{
		if (carriage_or_hub_assist_2(carriage, types, arg2) == 0)
		{
			carriage_jump(carriage);
			free(types);
			return (0);
		}
	}
	else if (types->type2 == 2)
		carriage_or_hub_assist_3(carriage, types, arg2);
	else
		carriage_or_hub_assist_4(carriage, types, arg2, temp);
	return (1);
}

int		carriage_or_hub_assist_1(t_carriage *carriage,
		t_types *types, int *arg1, int *temp)
{
	if (types->type1 == 1)
	{
		*arg1 = extract_1_byte(carriage->current_position + 2);
		if (!(*arg1 >= 1 && *arg1 <= 16))
			return (0);
		*arg1 = register_value(carriage, *arg1);
	}
	else if (types->type1 == 2)
		*arg1 = extract_4_bytes(carriage->current_position + 2);
	else if (types->type1 == 3)
	{
		*temp = extract_2_bytes(carriage->current_position + 2);
		*arg1 = extract_4_bytes((carriage->current_position +
		(*temp % IDX_MOD)) % 4096);
	}
	return (1);
}

int		carriage_or_hub_assist_2(t_carriage *carriage,
		t_types *types, int *arg2)
{
	if (types->type1 == 1)
		*arg2 = extract_1_byte(carriage->current_position + 3);
	else if (types->type1 == 2)
		*arg2 = extract_1_byte(carriage->current_position + 6);
	else if (types->type1 == 3)
		*arg2 = extract_1_byte(carriage->current_position + 4);
	if (!(*arg2 >= 1 && *arg2 <= 16))
		return (0);
	*arg2 = register_value(carriage, *arg2);
	return (1);
}

void	carriage_or_hub_assist_3(t_carriage *carriage,
		t_types *types, int *arg2)
{
	if (types->type1 == 1)
		*arg2 = extract_4_bytes(carriage->current_position + 3);
	else if (types->type1 == 2)
		*arg2 = extract_4_bytes(carriage->current_position + 6);
	else if (types->type1 == 3)
		*arg2 = extract_4_bytes(carriage->current_position + 4);
}
