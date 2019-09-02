/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_uppercase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:17:34 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 17:06:22 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_uppercase(char *str)
{
	if (str && *str)
	{
		while (*str)
		{
			if (!(str[0] > 64 && str[0] < 91))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
