/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   jump.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 11:28:24 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/22 11:28:27 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
** @desc Moves carriage to next operation code.
** @desc Then updates current operation code.
** @desc Then updates current cycles before exection.
** @desc Then updates jump that's necessary to get to next operation.
** @param t_carriage *carriage - carriage structure
** @return void
*/

void	carriage_jump(t_carriage *carriage)
{
	unsigned char *arena;

	arena = save_arena(NULL);
	carriage->current_position =
	(carriage->current_position + carriage->jump) % 4096;
	if (carriage->current_position < 0)
		carriage->current_position = 4096 + carriage->current_position;
}
