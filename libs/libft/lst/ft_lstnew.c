/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:15:20 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/16 13:05:05 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*new_cont;
	size_t	new_size;
	t_list	*new_lst;

	new_lst = 0;
	new_size = 0;
	new_cont = 0;
	if (content)
		if ((new_cont = malloc(sizeof(char) * (ft_strlen((char*)content)))))
			if ((new_cont = ft_memcpy(new_cont, (void*)content,
				(unsigned long int)content_size)))
				new_size = content_size;
	if ((new_lst = (t_list*)malloc(sizeof(t_list))))
	{
		new_lst->content = new_cont;
		new_lst->content_size = new_size;
		new_lst->next = 0;
		return (new_lst);
	}
	else
		return (0);
}
