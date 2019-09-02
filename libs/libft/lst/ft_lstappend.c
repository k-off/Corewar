/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 09:01:19 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/16 09:07:48 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (alst == NULL)
		return ;
	current = *alst;
	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	else
		*alst = new;
}
