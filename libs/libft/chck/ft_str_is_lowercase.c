/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_lowercase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:17:34 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:53:12 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_lowercase(char *str)
{
	if (str && *str)
	{
		while (*str)
		{
			if (!(str[0] > 96 && str[0] < 123))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
