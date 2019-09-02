/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:03:52 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:01:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char const *s, int n, int fd)
{
	size_t		i;

	if (s != 0 && fd > 0 && n > 0)
	{
		i = ft_strlen(s);
		if (n < (int)i)
			write(fd, s, n);
		else
			write(fd, s, i);
	}
}
