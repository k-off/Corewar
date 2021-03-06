/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isalpha.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:46:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/20 19:26:27 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int n)
{
	if ((n > 64 && n < 91) || (n > 96 && n < 123))
		return (1);
	return (0);
}
