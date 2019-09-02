/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:57:15 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/22 15:35:05 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst && src)
	{
		while (!(src[j] == '\0'))
			j++;
		if (size < 1)
			return (j);
		while (*src != '\0' && i < (size - 1))
		{
			dst[i] = (char)*src;
			i++;
			src++;
		}
		dst[i] = '\0';
		return (j);
	}
	return (0);
}
