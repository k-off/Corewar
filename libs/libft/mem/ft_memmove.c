/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:33 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:55:31 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	tmp = dst;
	if (&dst[0] < &src[0])
		while (i < n)
		{
			tmp[i] = ((unsigned char*)src)[i];
			i++;
		}
	else
		while (i < n)
		{
			n--;
			tmp[n] = ((unsigned char*)src)[n];
		}
	return (dst);
}
