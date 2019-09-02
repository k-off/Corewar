/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:38:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/17 19:03:52 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_rec(int n, int fd)
{
	if (n / 10)
		ft_putnbr_rec(n / 10, fd);
	if (n >= 0)
		ft_putchar_fd('0' + n % 10, fd);
	else
		ft_putchar_fd('0' - n % 10, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr_rec(n, fd);
}
