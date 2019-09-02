/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:29:33 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:54:41 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	tmp_dst = dst;
	tmp_src = (unsigned char*)src;
	while (i < n)
	{
		tmp_dst[i] = (unsigned char)(tmp_src[i] + '\0');
		i++;
	}
	return (dst);
}
