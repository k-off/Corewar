/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 17:58:39 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:56:34 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		len;
	int		half_len;
	int		i;
	char	tmp;

	len = (int)ft_strlen(s);
	half_len = len / 2;
	i = 0;
	while (i < half_len)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
		i++;
	}
	return (s);
}
