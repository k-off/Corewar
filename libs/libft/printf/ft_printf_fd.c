/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_inf_nan(t_data *data)
{
	if (data->llf != data->llf)
		data->s = ft_strdup("nan");
	else if (data->llf > LDBL_MAX)
		data->s = ft_strdup("inf");
	else if (data->llf < -LDBL_MAX)
		data->s = ft_strdup("-inf");
	if (data->llf != data->llf || data->llf > LDBL_MAX
		|| data->llf < -LDBL_MAX)
		return (1);
	return (0);
}

static void	float_convert(t_data *data)
{
	int		prec;

	prec = data->no_precision;
	if (check_inf_nan(data))
		data->print = data->s;
	else if (data->lll)
		data->s = ft_ldtoa(data->llf, (int)data->precision + prec);
	else if (data->l)
		data->s = ft_ldtoa((double)data->llf, (int)data->precision + prec);
	else
		data->s = ft_ldtoa(data->llf, (int)data->precision + prec);
	data->print = data->s;
	data->length = ft_strlen(data->s);
	handle_space_plus(data);
	handle_width(data);
}

static void	ft_conversion(t_data *data)
{
	if (data->conversion == 's' || data->conversion == 'c')
		string_convert(data);
	else if (data->conversion == 'd' || data->conversion == 'i')
		integer_convert(data);
	else if (data->conversion == 'u')
		unsigned_convert(data);
	else if (data->conversion == 'x' || data->conversion == 'X'
			|| data->conversion == 'p')
		hex_convert(data);
	else if (data->conversion == 'o')
		oct_convert(data);
	else if (data->conversion == 'f')
		float_convert(data);
	if (data->print && data->conversion != 'c')
		data->length = ft_strlen(data->print);
}

static void	ft_conversion_loop(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp)
	{
		ft_conversion(tmp);
		tmp = tmp->next;
	}
}

int			ft_printf_fd(int fd, const char *s, ...)
{
	va_list ap;
	int		d;
	t_data	*data;

	data = 0;
	if (ft_strlen(s) < 1 || (s[0] == '%' && ft_strlen(s) == 1))
		return (0);
	data = (t_data*)ft_memalloc(sizeof(t_data));
	va_start(ap, s);
	d = get_string(&data, s, ap);
	ft_conversion_loop(data);
	va_end(ap);
	if (d > 0)
		print_data_fd(data, &d, fd);
	free_data(&data);
	return (d - 1);
}
