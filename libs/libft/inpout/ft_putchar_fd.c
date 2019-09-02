/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 16:58:59 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 09:11:33 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(int c, int fd)
{
	if (fd > 0)
	{
		if (c >= 0 && c < 128)
			write(fd, &c, 1);
		else
			write(fd, &c, 2);
	}
}
