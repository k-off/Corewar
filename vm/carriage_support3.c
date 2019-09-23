/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage_support3.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:15:35 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/08/29 11:15:37 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	kill_carriages(t_carriage **carriages)
{
	int	i;

	i = 0;
	while (carriages[i] != NULL)
	{
		free(carriages[i]);
		i++;
	}
	free(carriages);
}

void	carriage_jump_free(t_carriage *carriage, t_types *types)
{
	carriage_jump(carriage);
	free(types);
}
