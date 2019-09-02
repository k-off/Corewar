/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcntw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 07:51:55 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:30:14 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcntw(char const *str)
{
	int	out;
	int	i;

	if (str == NULL)
		return (0);
	out = 0;
	i = 0;
	while (str[i])
		if (str[i] && !ft_isspace(str[i]))
		{
			++out;
			while (str[i] && !ft_isspace(str[i]))
				++i;
		}
		else
			while (ft_isspace(str[i]))
				++i;
	return (out);
}
