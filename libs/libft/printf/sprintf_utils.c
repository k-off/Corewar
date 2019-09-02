/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprintf_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_output(char **dst, t_data *data, int *d)
{
	char	**tmp;

	while (data)
	{
		if (data->length)
		{
			tmp = dst;
			if (*tmp == NULL)
				*dst = ft_strdup(data->print);
			else
			{
				*dst = ft_strjoin(*tmp, data->print);
				free(*tmp);
			}
			*d += data->length;
		}
		data = data->next;
	}
}

void	print_data_fd(t_data *data, int *d, int fd)
{
	while (data)
	{
		if (data->length)
		{
			*d += data->length;
			write(fd, data->print, data->length);
		}
		data = data->next;
	}
}
