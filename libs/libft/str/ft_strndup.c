/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 08:31:44 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 19:15:41 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	size_t		m;
	char		*dst;

	i = 0;
	m = ft_strlen(s);
	if (m > n)
		dst = (char*)malloc(sizeof(char) * (n + 1));
	if (m <= n)
		dst = (char*)malloc(sizeof(char) * (m + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] != '\0' && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
