/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncasencmp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:39:13 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 19:29:29 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	n--;
	while (i < n && !(s1[i] == '\0' || s2[i] == '\0' ||
		((ft_tolower(s1[i]) - ft_tolower(s2[i])) != 0)))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -
			(unsigned char)ft_tolower(s2[i]));
}
