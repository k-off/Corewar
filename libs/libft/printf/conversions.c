/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_convert(t_data *data)
{
	if (data->conversion == 'c')
	{
		handle_modifiers(data, (long long *)&data->ch, NULL);
		data->s = ft_strdup(&data->ch);
		data->print = ft_strdup(data->s);
	}
	else
	{
		if (data->precision < 1 && !data->dot)
			data->print = ft_strdup(data->s);
		else
			data->print = ft_strndup(data->s, data->precision);
	}
	free(data->s);
	data->s = data->print;
	data->length = ft_strlen(data->s);
	if (data->conversion == 'c')
		data->length = 1;
	handle_width(data);
}

void	integer_convert(t_data *data)
{
	handle_modifiers(data, &data->lld, NULL);
	if (data->lld == 0 && data->precision == 0 && data->no_precision == -1)
		data->s = ft_strdup("\0");
	else if (!(data->l || data->ll))
		data->s = ft_lltoa_base((int)data->lld, 10, 0);
	else
		data->s = ft_lltoa_base(data->lld, 10, 0);
	data->print = data->s;
	data->length = ft_strlen(data->s);
	handle_precision(data);
	handle_space_plus(data);
	handle_width(data);
}

void	unsigned_convert(t_data *data)
{
	handle_modifiers(data, NULL, &data->uld);
	if (data->uld == 0 && data->precision == 0 && data->no_precision == -1)
		data->s = ft_strdup("\0");
	else if (!(data->l || data->ll))
		data->s = ft_ulltoa_base((unsigned)data->uld, 10, data->hash);
	else
		data->s = ft_ulltoa_base(data->uld, 10, data->hash);
	data->print = data->s;
	data->length = ft_strlen(data->s);
	handle_precision(data);
	handle_width(data);
}

void	hex_convert(t_data *data)
{
	handle_modifiers(data, NULL, &data->uld);
	if ((data->dot || (data->hash && data->dot)) && !data->uld)
		data->s = ft_strdup("\0");
	else
	{
		if (!(data->l || data->ll) && data->uld > 0)
			data->s = ft_ulltoa_base((unsigned)data->uld, 16,
							data->conversion == 'X');
		else
			data->s = ft_ulltoa_base(data->uld, 16, data->conversion == 'X');
		check_pointer(&data->s, data->conversion, data->uld);
		data->length = ft_strlen(data->s);
		if (data->precision)
			data->zero = 0;
		if (data->zero && !data->minus && data->width > data->precision
			&& data->width > data->length)
		{
			data->precision = data->width;
			if (data->hash)
				data->precision -= 2;
		}
	}
	handle_precision(data);
	handle_hash(data);
	handle_width(data);
}

void	oct_convert(t_data *data)
{
	handle_modifiers(data, NULL, &data->uld);
	if (data->precision == 0 && data->dot && !data->hash)
		data->s = ft_strdup("\0");
	else if (!(data->l || data->ll))
		data->s = ft_ulltoa_base((unsigned)data->uld, 8, 0);
	else
		data->s = ft_ulltoa_base(data->uld, 8, 0);
	data->length = ft_strlen(data->s);
	handle_precision(data);
	handle_hash(data);
	handle_width(data);
}
