/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:06:15 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:06:16 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
** @desc Checks if every char in a argument is a number.
** @param char *s - a string of characters.
** @return int which represents true or false.
*/

int		arg_is_a_nbr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** @desc Given args byte describing arguments of an
** @desc operation, extract information about 2 arguments.
** @desc It is used for operations with 2 arguments.
** @desc type 1 or 01 is register
** @desc type 2 or 10 is direct value T_DIR
** @desc type 3 or 11 is indirect value T_IND
** @param unsigned char arg_byte - args byte storing data about arguments
** @return t_types * address of a structure storing data about arguments.
*/

t_types	*extract_types_2(unsigned char arg_byte)
{
	int		arg1;
	int		arg2;
	t_types	*types;

	types = (t_types*)ft_memalloc(sizeof(t_types));
	arg_byte = arg_byte >> 4;
	arg2 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg1 = arg_byte & 3;
	types->type1 = arg1;
	types->type2 = arg2;
	return (types);
}

/*
** @desc Given args byte describing arguments of an
** @desc operation, extract information about 3 arguments.
** @desc It is used for operations with 3 arguments.
** @desc type 1 or 01 is register
** @desc type 2 or 10 is direct value T_DIR
** @desc type 3 or 11 is indirect value T_IND
** @param unsigned char arg_byte - args byte storing data about arguments
** @return t_types * address of a structure storing data about arguments.
*/

t_types	*extract_types_3(unsigned char arg_byte)
{
	int		arg1;
	int		arg2;
	int		arg3;
	t_types	*types;

	types = (t_types*)ft_memalloc(sizeof(t_types));
	arg_byte = arg_byte >> 2;
	arg3 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg2 = arg_byte & 3;
	arg_byte = arg_byte >> 2;
	arg1 = arg_byte & 3;
	types->type1 = arg1;
	types->type2 = arg2;
	types->type3 = arg3;
	return (types);
}

/*
** @desc Check if register is between 1 and 16, as 1-16
** @desc are valid registers.
** @param int reg - register value to be checked
** @return 1 if register is valid
** @return 0 if register is not valid
*/

int		valid_register(int reg)
{
	if (reg >= 1 && reg <= 16)
		return (1);
	return (0);
}

/*
** @desc Introduce players of the game
** @param t_players **players - array of players structures
** @return void
*/

void	introduce_players(t_players **players)
{
	int	i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (players[i] != NULL && i < 4)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		players[i]->id, players[i]->executable_size, players[i]->name,
		players[i]->comment);
		i++;
	}
}
