/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:11:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:07:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char		*s_c;

	s_c = (unsigned char*)s;
	while (n > 0)
	{
		n--;
		if ((unsigned char)c == s_c[n])
			return ((void*)(&s[n]));
	}
	return (0);
}
