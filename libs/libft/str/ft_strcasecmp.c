/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcasecmp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:39:13 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 18:20:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (!(s1[i] == '\0' || s2[i] == '\0' ||
		((ft_tolower(s1[i]) - ft_tolower(s2[i])) != 0)))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -
			(unsigned char)ft_tolower(s2[i]));
}
