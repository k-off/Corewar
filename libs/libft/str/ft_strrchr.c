/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:58:39 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:56:34 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *adr;

	adr = 0;
	while (s[0] != '\0')
	{
		if (s[0] == c)
			adr = &s[0];
		s++;
	}
	if (s[0] == c)
		adr = &s[0];
	return ((char*)adr);
}
