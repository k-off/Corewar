/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_alpha.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 16:11:38 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:41:10 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	if (str && *str)
	{
		while (*str)
		{
			if (!(ft_isalpha(str[0])))
				return (0);
			str++;
		}
		return (1);
	}
	return (0);
}
