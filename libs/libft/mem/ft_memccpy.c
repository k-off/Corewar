/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:33 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:49:08 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*tmp_dst;
	unsigned char			*tmp_src;

	i = 0;
	if (n == 0)
		return (0);
	if (dst == src)
		return (dst);
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_dst[i] == (unsigned char)c)
			return (&dst[i] + 1);
		i++;
	}
	return (0);
}
