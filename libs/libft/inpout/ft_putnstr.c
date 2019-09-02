/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:03:52 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:01:21 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, int n)
{
	size_t		i;

	if (s != 0 && n > 0)
	{
		i = ft_strlen(s);
		if (n < (int)i)
			write(1, s, n);
		else
			write(1, s, i);
	}
}
