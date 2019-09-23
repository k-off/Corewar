/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 14:08:38 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 14:08:40 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc If 'ldi' command is executed by carriage,
** @desc then it adds distance1 and distance2 to get to new postion
** @desc and writes result to register.
** @desc distance1 can be originally T_REG, T_DIR or T_IND,
** @desc distance2 can be originally T_REG, T_DIR,
** @desc and must be supplied by the calling function.
** @param t_carriage *carriage - carriage structure
** @param int distance1 - distance 1 for addition
** @param int distance2 - distance 2 for addition
** @param int reg - register receiving value
** @return void
*/

void	carriage_ldi(t_carriage *carriage,
		int distance1, int distance2, int reg)
{
	unsigned char	*arena;
	int				location;

	arena = save_arena(NULL);
	location = (carriage->current_position +
	((distance1 + distance2) % IDX_MOD)) % 4096;
	if (location < 0)
		location = 4096 + location;
	register_write(carriage, reg, extract_4_bytes(location));
}
