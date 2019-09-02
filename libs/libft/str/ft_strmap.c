/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:00:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 10:55:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *src, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*dst;

	dst = 0;
	if (src != 0)
	{
		len = ft_strlen(src);
		dst = (char *)malloc(sizeof(char) * (len + 1));
		if (dst)
		{
			i = 0;
			while (i < len)
			{
				dst[i] = f(src[i]);
				i++;
			}
			dst[i] = '\0';
		}
	}
	return (dst);
}
