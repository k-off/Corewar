/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:58:39 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:55:59 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (s[0] != '\0')
	{
		if (s[0] == c)
			return ((char*)s);
		s++;
	}
	if (s[0] == c)
		return ((char*)s);
	return (0);
}
