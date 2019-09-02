/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:23:50 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:43:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char				*dst;

	dst = 0;
	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	else
	{
		dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (dst == 0)
			return (0);
		dst = ft_strcpy(dst, s1);
		dst = ft_strcat(dst, s2);
	}
	return (dst);
}
