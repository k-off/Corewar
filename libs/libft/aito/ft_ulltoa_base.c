/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long n, int base, int is_upper)
{
	char	str[65];
	char	*tmp;
	char	*xnbrs[2];

	xnbrs[0] = "0123456789abcdefghijklmnopqrstuvwxyz";
	xnbrs[1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	str[64] = '\0';
	tmp = &str[63];
	if (n == 0)
	{
		*tmp = '0';
		tmp--;
	}
	while (n != 0)
	{
		*tmp = xnbrs[is_upper][n % base];
		tmp--;
		n /= base;
	}
	tmp++;
	return (ft_strdup(tmp));
}
