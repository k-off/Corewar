/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:25:37 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/16 12:57:16 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	new_list = 0;
	if (lst && f)
		if (lst)
			if ((new_list = malloc(sizeof(t_list))))
			{
				new_list->content = (f(lst))->content;
				new_list->content_size = (f(lst))->content_size;
				new_list->next = ft_lstmap(lst->next, f);
			}
	return (new_list);
}
