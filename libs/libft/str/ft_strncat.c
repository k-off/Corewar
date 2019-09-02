/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:57:15 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:57:19 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (j < (n) && src[j] != '\0')
	{
		dst[i + j] = (char)src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
