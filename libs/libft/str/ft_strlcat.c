/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:57:15 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:58:17 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	i = 0;
	j = 0;
	k = 0;
	tmp = (char*)src;
	while (!(dst[i] == '\0'))
		i++;
	while (!(src[j] == '\0'))
		j++;
	if (size <= i)
		return (j + size);
	k = i;
	while (*src != '\0' && k < (size - 1))
	{
		dst[k] = *tmp;
		k++;
		tmp++;
	}
	dst[k] = '\0';
	return (i + j);
}
