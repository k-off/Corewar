/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strupcase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 18:43:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 18:50:25 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *s)
{
	int		i;

	i = 0;
	if (s && *s)
		while (s[i])
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	return (s);
}
