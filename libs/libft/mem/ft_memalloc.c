/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:22:27 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:09:43 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = 0;
	if (size > 0)
	{
		mem = malloc(size);
		if (mem)
			ft_bzero(mem, size);
	}
	return (mem);
}
