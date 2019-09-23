/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lldi2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:19:30 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 14:19:31 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'lldi' command is executed by carriage,
** @desc then it adds distance1 and distance2 to get to new postion
** @desc and writes result to register.
** @desc num1 can be originally T_REG, T_DIR or T_IND,
** @desc num2 can be originally T_REG, T_DIR,
** @desc and must be supplied by the calling function.
** @desc Difference between this and 'ldi' is that
** @desc modulo is not applied to the sum of new distance.
** @desc In 'ldi' we use (distance1 + distance2) % IDX_MOD
** @desc In 'lldi' we use (distance1 + distance2)
** @desc % 4096 is applied because memory works in circular fashion
** @desc and with lldi a bigger jump can be done.
** @desc But if distance1 was T_IND, then it is obtained with IDX_MOD
** @param t_carriage *carriage - carriage structure
** @param int distance1 - number 1 for total distance
** @param int distance2 - number 2 for total distance
** @return void
*/

void	carriage_lldi(t_carriage *carriage,
		int distance1, int distance2, int reg)
{
	unsigned char	*arena;
	int				location;

	arena = save_arena(NULL);
	location = (carriage->current_position +
	(distance1 + distance2)) % 4096;
	if (location < 0)
		location = 4096 + location;
	if (extract_4_bytes(location) == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
	register_write(carriage, reg, extract_4_bytes(location));
}
