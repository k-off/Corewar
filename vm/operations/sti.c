/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:27:37 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:27:38 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'sti' command is executed by carriage,
** @desc then carriage_add_hub extracts information
** @desc about the arguments and determines their types
** @desc extract_types_3 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If and has received valid 3 arguments, it extracts
** @desc argument values and sends them to carriage_sti function,
** @desc which actually executes the command. Thus carriage_sti_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_sti_hub(t_carriage *carriage, unsigned char *arena)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		temp;
	t_types	*types;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	types = extract_types_3(arena[(carriage->current_position + 1) % 4096]);
	if (types->type1 == 1 && (types->type3 == 1 || types->type3 == 2)
	&& types->type2 != 0)
	{
		arg1 = extract_1_byte(carriage->current_position + 2);
		if (carriage_sti_hub2(carriage, types, &arg1) == 0)
			return ;
		if (carriage_sti_hub_assist_1(carriage, types, &arg2, &temp) == 0
		|| carriage_sti_hub_assist_2(carriage, types, &arg3) == 0)
		{
			carriage_jump_free(carriage, types);
			return ;
		}
		carriage_sti(carriage, arg2, arg3, arg1);
	}
	free(types);
	carriage_jump(carriage);
}

int		carriage_sti_hub2(t_carriage *carriage,
		t_types *types, int *arg1)
{
	if (!valid_register(*arg1))
	{
		carriage_jump(carriage);
		free(types);
		return (0);
	}
	*arg1 = register_value(carriage, *arg1);
	return (1);
}

int		carriage_sti_hub_assist_1(t_carriage *carriage,
		t_types *types, int *arg2, int *temp)
{
	if (types->type2 == 1)
	{
		*arg2 = extract_1_byte(carriage->current_position + 3);
		if (!(*arg2 >= 1 && *arg2 <= 16))
			return (0);
		*arg2 = register_value(carriage, *arg2);
	}
	else if (types->type2 == 2)
		*arg2 = extract_2_bytes(carriage->current_position + 3);
	else if (types->type2 == 3)
	{
		*temp = extract_2_bytes(carriage->current_position + 3);
		*arg2 = (carriage->current_position +
		(*temp % IDX_MOD)) % 4096;
		if (*arg2 < 0)
			*arg2 = 4096 + *arg2;
		*arg2 = extract_4_bytes(*arg2);
	}
	return (1);
}

int		carriage_sti_hub_assist_2(t_carriage *carriage,
		t_types *types, int *arg3)
{
	if (types->type3 == 1)
	{
		if (types->type2 == 1)
			*arg3 = extract_1_byte(carriage->current_position + 4);
		else if (types->type2 == 2)
			*arg3 = extract_1_byte(carriage->current_position + 5);
		else if (types->type2 == 3)
			*arg3 = extract_1_byte(carriage->current_position + 5);
		if (!(*arg3 >= 1 && *arg3 <= 16))
			return (0);
		*arg3 = register_value(carriage, *arg3);
	}
	else if (types->type3 == 2)
	{
		if (types->type2 == 1)
			*arg3 = extract_2_bytes(carriage->current_position + 4);
		else if (types->type2 == 2)
			*arg3 = extract_2_bytes(carriage->current_position + 5);
		else if (types->type2 == 3)
			*arg3 = extract_2_bytes(carriage->current_position + 5);
	}
	return (1);
}
