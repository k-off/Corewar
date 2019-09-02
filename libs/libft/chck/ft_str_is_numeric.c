/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_numeric.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:23:07 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:25:53 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_numeric(char *str)
{
	if (str && *str)
	{
		while (*str)
		{
			if (!(ft_isdigit(str[0])))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
