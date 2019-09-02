/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_handlers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_modifiers(t_data *data, long long *n, unsigned long long *u)
{
	if (data->ll && n)
		*n = (long long)*n;
	else if (data->ll && *u)
		*u = (unsigned long long)*u;
	else if (data->l && n)
		*n = (long)*n;
	else if (data->l && u)
		*u = (unsigned long)*u;
	else if (data->h && n)
		*n = (short)*n;
	else if (data->h && u)
		*u = (unsigned short)*u;
	else if (data->hh && n)
		*n = (char)*n;
	else if (data->hh && u)
		*u = (unsigned char)*u;
}

void	handle_width(t_data *data)
{
	char		*t;
	char		c;
	long long	diff;
	long long	i;

	if (data->width > data->length)
	{
		diff = data->width - data->length;
		i = 0;
		t = (char*)ft_memalloc(sizeof(char) * (diff + 1));
		if (data->zero != 0 && data->minus == 0 &&
			!(data->conversion == 'o' && data->precision != 0)
			&& !(data->conversion == 'd' && data->precision != 0))
			c = '0';
		else
			c = ' ';
		fill_str(t, c, diff);
		if ((data->s[0] == '-' || data->s[0] == '+' || data->s[0] == ' ')
		&& t[0] == '0')
		{
			t[0] = data->s[0];
			data->s[0] = '0';
		}
		width_utils(data, &t);
	}
}

void	handle_precision(t_data *data)
{
	char		*tmp;

	if (data->precision > data->length - (data->s[0] == '-'))
	{
		if (data->s[0] == '-')
			data->precision++;
		tmp = ft_memalloc(sizeof(char) * (data->precision - data->length + 1));
		fill_str(tmp, '0', data->precision - data->length);
		if (data->s[0] == '-')
		{
			data->s[0] = '0';
			tmp[0] = '-';
		}
		data->print = ft_strjoin(tmp, data->s);
		free(data->s);
		free(tmp);
		data->s = data->print;
		data->length = ft_strlen(data->s);
	}
}

void	handle_hash(t_data *data)
{
	char *tmp;

	tmp = "";
	if (data->uld > 0 || data->pointer_precision)
	{
		if ((data->hash && data->conversion == 'x') || data->conversion == 'p')
			tmp = "0x\0";
		else if (data->hash && data->conversion == 'X')
			tmp = "0X\0";
		else if (data->hash && data->conversion == 'o' && data->s[0] != '0')
			tmp = "0\0";
	}
	else
	{
		if (data->conversion == 'p' && data->dot)
			tmp = "0x\0";
	}
	data->print = ft_strjoin(tmp, data->s);
	free(data->s);
	data->s = data->print;
	data->length = ft_strlen(data->s);
}

void	handle_space_plus(t_data *data)
{
	char	tmp[2];

	tmp[0] = data->s[0];
	tmp[1] = 0;
	if (data->space && tmp[0] != '-')
		tmp[0] = ' ';
	if (data->plus && tmp[0] != '-')
		tmp[0] = '+';
	if ((data->space || data->plus) && tmp[0] != '-')
	{
		data->print = ft_strjoin(tmp, data->s);
		free(data->s);
		data->s = data->print;
	}
	data->length = ft_strlen(data->s);
}
