/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriages_support2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 14:20:01 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/17 14:20:03 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Based on argument type, increase sum integer in triple_arg function.
** @param int arg1 - argument 1 of an operation
** @param int arg2 - argument 2 of an operation
** @param int arg3 - argument 3 of an operation
** @param unsigned int opcode - operation code to find out direct argument size
** @return void
*/

static int	triple_arg_support(int arg1, int arg2,
							int arg3, unsigned int opcode)
{
	int sum;

	sum = 0;
	if (arg1 == 1)
		sum = sum + 1;
	else if (arg1 == 2)
		sum = sum + single_arg_dir(opcode);
	else if (arg1 == 3)
		sum = sum + 2;
	if (arg2 == 1)
		sum = sum + 1;
	else if (arg2 == 2)
		sum = sum + single_arg_dir(opcode);
	else if (arg2 == 3)
		sum = sum + 2;
	if (arg3 == 1)
		sum = sum + 1;
	else if (arg3 == 2)
		sum = sum + single_arg_dir(opcode);
	else if (arg3 == 3)
		sum = sum + 2;
	return (sum);
}

/*
** @desc If operation has three arguments, then get to know
** @desc their types (01 is type 1, 10 is type 2 and 11 is type 3)
** @desc and then get sum of arguments.
** @param unsigned char arg_byte - argument byte describing arguments
** @param int opcode - operation code
** @return int sum as size of arguments as informed by argument byte
*/

int			triple_arg(unsigned char arg_byte, unsigned int opcode)
{
	int arg1;
	int	arg2;
	int	arg3;
	int sum;

	if (arg_byte == 0)
		return (0);
	sum = 0;
	arg_byte = arg_byte >> 2;
	arg3 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg2 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg1 = arg_byte & 3;
	sum = triple_arg_support(arg1, arg2, arg3, opcode);
	return (sum);
}

/*
** @desc If operation has two arguments, then get to know
** @desc their types (01 is type 1, 10 is type 2 and 11 is type 3)
** @desc and then get sum of arguments.
** @param unsigned char arg_byte - argument byte describing arguments
** @param int opcode - operation code
** @return int sum as size of arguments as informed by argument byte
*/

int			double_arg(unsigned char arg_byte, unsigned int opcode)
{
	int arg1;
	int	arg2;
	int sum;

	sum = 0;
	if (arg_byte == 0)
		return (0);
	arg_byte = arg_byte >> 4;
	arg2 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg1 = arg_byte & 3;
	if (arg1 == 1)
		sum = sum + 1;
	else if (arg1 == 2)
		sum = sum + single_arg_dir(opcode);
	else if (arg1 == 3)
		sum = sum + 2;
	if (arg2 == 1)
		sum = sum + 1;
	else if (arg2 == 2)
		sum = sum + single_arg_dir(opcode);
	else if (arg2 == 3)
		sum = sum + 2;
	return (sum);
}

/*
** @desc Check if operation code is between 1 and 16
** @param unsigned int opcode - operation code to be checked
** @return int 1 if operatio code is valid
** @return int 0 if operatio code is not valid
*/

int			validate_opcode(unsigned int opcode)
{
	if (opcode >= 1 && opcode <= 16)
		return (1);
	return (0);
}

/*
** @desc Based on current opcode within an array at specific
** @desc index, calculate jump that is necessary to do.
** @desc If opcode is invalid, jump must be 1 byte. If arguments
** @desc byte was overwritten such that one of arguments is of wrong
** @desc type, then argument byte needs to be skipped too and also
** @desc all arguments. If one of registers is invalid, then
** @desc opcode + args byte if present + arguments are skipped.
** @desc IT IS NOT FULL VALIDATOR, AS EVEN IF SOME ARGS ARE INCORRECT
** @desc THEN THE JUMP IS STILL OPCODE + ARGS BYTE + ARGS SIZE.
** @param unsigned int opcode - operation code
** @param unsigned char *arena - arena with filled executables
** @param int position - index of player's executable within arena
** @return int as bytes for carriage to jump over
*/

int			calculate_jump(unsigned int opcode,
			unsigned char *arena, int position)
{
	if (validate_opcode(opcode) == 0)
		return (1);
	if (opcode == 16)
		return (aff_calculate_jump(arena, position));
	if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
		return (1 + single_arg_dir(opcode));
	if (opcode == 2 || opcode == 3 || opcode == 13)
		return (1 + 1 + double_arg(arena[(position + 1) % 4096], opcode));
	if (opcode == 4 || opcode == 5 || opcode == 6 || opcode == 7
	|| opcode == 8 || opcode == 10 || opcode == 11 || opcode == 14)
		return (1 + 1 + triple_arg(arena[(position + 1) % 4096], opcode));
	return (1);
}
