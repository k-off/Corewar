/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 08:31:44 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:29:28 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		n;
	int		i;
	char	*dst;

	i = 0;
	n = 0;
	while (s[n] != '\0')
		n++;
	dst = (char*)malloc(sizeof(char) * (n + 1));
	if (dst == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
