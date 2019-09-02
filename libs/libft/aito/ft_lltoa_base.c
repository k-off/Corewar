/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lltoa_base(long long n, int base, int is_upper)
{
	char	minus;
	char	*s;
	char	*ret;

	if (n < 0)
	{
		minus = '-';
		s = ft_ulltoa_base(-n, base, is_upper);
		if (base == 10)
			ret = ft_strjoin(&minus, s);
		else
			ret = ft_strdup(s);
		free(s);
		return (ret);
	}
	return (ft_ulltoa_base(n, base, is_upper));
}
