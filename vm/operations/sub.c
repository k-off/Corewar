/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:39 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:23:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'sub' command is executed by carriage,
** @desc then carriage_sub_hub extracts information
** @desc about the arguments and determines their types
** @desc extract_types_3 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If and has received valid 3 arguments, it extracts
** @desc argument values and sends them to carriage_sub function,
** @desc which actually executes the command. Thus carriage_sub_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_sub_hub(t_carriage *carriage, unsigned char *arena)
{
	int		arg1;
	int		arg2;
	int		arg3;
	t_types	*types;

	carriage->jump =
	calculate_jump(carriage->current_opcode, arena, carriage->current_position);
	types = extract_types_3(arena[(carriage->current_position + 1) % 4096]);
	if (types->type1 == 1 && types->type2 == 1 && types->type3 == 1)
	{
		arg1 = extract_1_byte(carriage->current_position + 2);
		arg2 = extract_1_byte(carriage->current_position + 3);
		arg3 = extract_1_byte(carriage->current_position + 4);
		if (valid_register(arg1) &&
		valid_register(arg2) && valid_register(arg3))
			carriage_sub(carriage, arg1, arg2, arg3);
	}
	free(types);
	carriage_jump(carriage);
}

/*
** @desc If 'sub' command is executed by carriage,
** @desc then it substracts reg2 from reg1
** @desc and writes result to reg3 register and changes carry if necessary.
** @desc register or (Current position + T_IND) % IDX_MOD place in arena.
** @param t_carriage *carriage - carriage structure
** @param int reg1 - source register number 1
** @param int reg2 - source register number 2
** @param int reg3 - destination register
** @return void
*/

void	carriage_sub(t_carriage *carriage, int reg1, int reg2, int reg3)
{
	int	sum;

	sum = register_value(carriage, reg1) - register_value(carriage, reg2);
	register_write(carriage, reg3, sum);
	if (sum == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
