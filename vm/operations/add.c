/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:23:33 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:23:35 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'add' command is executed by carriage,
** @desc then carriage_add_hub extracts information
** @desc about the arguments and determines whether
** @desc or not all of them are registers.
** @desc extract_types_3 extracts type of arguments
** @desc from arguments byte. Type 1 is register,
** @desc type 2 is direct value T_DIR and type 3 is indirect T_IND.
** @desc If add has received valid 3 registers, it extracts
** @desc argument values and sends them to carriage_add function,
** @desc which actually executes the command. Thus carriage_add_hub
** @desc extracts data and validates it and sends it further.
** @param t_carriage *carriage - carriage structure
** @param unsigned char *arena - arena of the game
** @return void
*/

void	carriage_add_hub(t_carriage *carriage, unsigned char *arena)
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
		if (valid_register(arg1) && valid_register(arg2)
		&& valid_register(arg3))
			carriage_add(carriage, arg1, arg2, arg3);
	}
	free(types);
	carriage_jump(carriage);
}

/*
** @desc If 'add' command is executed by carriage,
** @desc then it adds values of reg1 and reg2 registers
** @desc and writes them to reg3 register and changes carry if necessary.
** @desc register or (Current position + T_IND) % IDX_MOD place in arena.
** @param t_carriage *carriage - carriage structure
** @param int reg1 - source register number 1
** @param int reg2 - source register number 2
** @param int reg3 - destination register
** @return void
*/

void	carriage_add(t_carriage *carriage, int reg1, int reg2, int reg3)
{
	int	sum;

	sum = register_value(carriage, reg1) + register_value(carriage, reg2);
	register_write(carriage, reg3, sum);
	if (sum == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
