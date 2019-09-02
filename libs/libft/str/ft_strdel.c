/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:52:34 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 14:06:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **ap)
{
	if (ap != NULL)
	{
		if (*ap != NULL)
			free(*ap);
		*ap = NULL;
	}
}
