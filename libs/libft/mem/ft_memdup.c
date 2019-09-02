/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:33 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:54:41 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*tmp;

	if (src == NULL || n == 0)
		return (0);
	dst = (unsigned char*)malloc(n);
	tmp = (unsigned char*)src;
	while (n > 0)
	{
		n--;
		dst[n] = tmp[n];
	}
	return (dst);
}
