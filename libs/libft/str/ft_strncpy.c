/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 07:51:55 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:31:55 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[0];
		if (src[0] != '\0')
			src++;
		i++;
	}
	return (dest);
}
