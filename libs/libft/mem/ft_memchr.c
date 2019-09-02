/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:11:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:07:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*s_c;
	size_t				i;

	i = 0;
	s_c = (unsigned char*)s;
	while (i < n)
	{
		if ((unsigned char)c == s_c[i])
			return ((void*)(&s[i]));
		i++;
	}
	return (0);
}
