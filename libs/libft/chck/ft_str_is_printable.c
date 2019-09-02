/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_printable.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 17:00:12 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 17:04:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_printable(char *str)
{
	if (str && *str)
	{
		while (*str)
		{
			if (!(ft_isprint(str[0])))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
