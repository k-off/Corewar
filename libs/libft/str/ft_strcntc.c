/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcntc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 07:51:55 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:30:14 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcntc(char const *str, char c)
{
	int	out;
	int	i;

	if (str == NULL)
		return (0);
	out = 0;
	i = 0;
	while (str[i])
		if (str[i++] == c)
			++out;
	return (out);
}
