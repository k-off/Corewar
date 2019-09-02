/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa_base(unsigned long n, int base, int is_upper)
{
	char	str[33];
	char	*tmp;
	char	*xnbrs[2];

	xnbrs[0] = "0123456789abcdefghijklmnopqrstuvwxyz";
	xnbrs[1] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	str[32] = '\0';
	tmp = &str[31];
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

char		*ft_itoa_base(long n, int base, int is_upper)
{
	char	minus;
	char	*s;
	char	*ret;

	if (n < 0)
	{
		minus = '-';
		s = ft_utoa_base(-n, base, is_upper);
		if (base == 10)
			ret = ft_strjoin(&minus, s);
		else
			ret = ft_strdup(s);
		free(s);
		return (ret);
	}
	return (ft_utoa_base(n, base, is_upper));
}
