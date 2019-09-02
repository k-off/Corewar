/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:57:16 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:08:54 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	sub = 0;
	if (s != 0)
		if ((sub = (char*)malloc(sizeof(char) * (len + 1))))
		{
			while (i < (start + len) && s[i] != '\0')
			{
				if (i >= start)
				{
					sub[j] = s[i];
					j++;
				}
				i++;
			}
			sub[j] = '\0';
		}
	return (sub);
}
