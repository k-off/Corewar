/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcapitalize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 17:15:07 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 18:05:59 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int		i;

	i = 0;
	if (s && *s)
		while (s[i] != '\0')
		{
			if (ft_islower(s[i]) && (i == 0 || !ft_isalnum(s[i - 1])))
				s[i] = s[i] - 32;
			if (ft_isupper(s[i]) && (i != 0 && ft_isalnum(s[i - 1])))
				s[i] = s[i] + 32;
			i++;
		}
	return (s);
}
