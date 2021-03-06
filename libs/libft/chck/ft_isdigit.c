/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isdigit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:39:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/20 19:44:40 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int n)
{
	if (n > 47 && n < 58)
		return (1);
	return (0);
}
