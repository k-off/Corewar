/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stracat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 18:57:15 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 11:56:39 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stracat(char *str1, char *str2)
{
	size_t	size;
	char	*out;
	char	*ptr;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL)
		return (ft_strndup(str2, ft_strlen(str2)));
	if (str2 == NULL)
		return (ft_strndup(str1, ft_strlen(str1)));
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	out = (char*)ft_memalloc(size * sizeof(char));
	if (out == NULL)
		return (NULL);
	ptr = out;
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	*ptr = '\0';
	return (out);
}
