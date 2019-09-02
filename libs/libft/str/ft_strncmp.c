/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:39:13 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:02:38 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n < 1)
		return (0);
	n--;
	while (!(s1[i] == '\0' || s2[i] == '\0' || i >= n || (s1[i] - s2[i] != 0)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
