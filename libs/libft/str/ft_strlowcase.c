/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlowcase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 18:43:44 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 18:48:30 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *s)
{
	int		i;

	i = 0;
	if (s && *s)
		while (s[i])
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	return (s);
}
