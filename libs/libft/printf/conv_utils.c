/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_utils(t_data *data, char **t)
{
	data->length = ft_strlen(data->s) + ft_strlen(*t);
	if (data->conversion == 'c')
		data->length = 1 + ft_strlen(*t);
	if (data->minus && data->conversion == 'c' && data->ch == 0)
	{
		data->print = ft_strjoin("0\0", *t);
		data->print[0] = 0;
	}
	else if (data->minus)
		data->print = ft_strjoin(data->s, *t);
	else if (data->conversion == 'c' && data->ch == 0)
	{
		data->print = ft_strjoin(*t, "0\0");
		data->print[data->length - 1] = 0;
	}
	else
		data->print = ft_strjoin(*t, data->s);
	free(data->s);
	free(*t);
	data->s = data->print;
}
