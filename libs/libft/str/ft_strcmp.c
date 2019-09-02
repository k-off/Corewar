/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:39:13 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 15:23:53 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (!(s1[i] == '\0' || s2[i] == '\0' || (s1[i] - s2[i] != 0)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
