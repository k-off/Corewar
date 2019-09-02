/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion(char c)
{
	char	*conversions;
	int		i;

	i = 0;
	conversions = "cspdiuoxXf%";
	while (i < 11)
	{
		if (c == conversions[i])
			return (1);
		i++;
	}
	return (0);
}

static void	check_string(t_data *data, va_list ap)
{
	char	*tmp;

	tmp = va_arg(ap, char *);
	if (tmp == 0)
		data->s = ft_strdup("(null)");
	else
		data->s = ft_strdup(tmp);
}

static void	convert_to_data(t_data *data, va_list ap, char c)
{
	data->conversion = c;
	if (c == 'c')
		data->ch = va_arg(ap, int);
	else if (c == 's')
		check_string(data, ap);
	else if (c == 'p' || c == 'u' || c == 'o' || c == 'x' || c == 'X')
		data->uld = va_arg(ap, unsigned long long);
	else if (c == 'd' || c == 'i')
		data->lld = va_arg(ap, long long);
	else if (c == 'f' && data->lll > 0)
		data->llf = va_arg(ap, long double);
	else if (c == 'f' && data->l + data->ll > 0)
		data->llf = va_arg(ap, double);
	else if (c == 'f' && data->l + data->ll + data->lll == 0)
		data->llf = va_arg(ap, double);
	else if (c == '%')
	{
		data->ch = '%';
		data->conversion = 'c';
	}
}

static int	get_data(t_data **data, const char *s, va_list ap)
{
	int		i;

	i = 0;
	data[0]->no_precision = 0;
	while (!(s[i] == 0 || is_conversion(s[i])))
		flags_1(*data, s, &i, ap);
	if (s[i] == 0)
		return (-1);
	convert_to_data(*data, ap, s[i]);
	if (data[0]->precision <= 0 && data[0]->conversion != 's')
		data[0]->precision = 0;
	if ((data[0]->precision || (data[0]->uld > 0 && data[0]->uld < 65536))
		&& data[0]->conversion == 'p')
	{
		data[0]->conversion = 'x';
		data[0]->pointer_precision = 1;
		data[0]->hash = 1;
	}
	i++;
	if (s[i] == 0)
		return (1);
	data[0]->next = (t_data*)ft_memalloc(sizeof(t_data));
	return (1 * get_string(&(data[0])->next, &s[i], ap));
}

int			get_string(t_data **data, const char *s, va_list ap)
{
	int		i;

	i = 0;
	while (!(s[i] == 0 || s[i] == '%'))
		i++;
	if (i < 1 && s[i] == 0)
		return (1);
	if (i)
		data[0]->print = (char*)ft_memalloc(sizeof(char) * (i + 1));
	data[0]->length = i;
	data[0]->print = ft_strncpy(data[0]->print, s, data[0]->length);
	if (s[i] == '%' && data[0]->length)
	{
		data[0]->next = (t_data*)ft_memalloc(sizeof(t_data));
		return (1 * get_data(&(data[0])->next, &s[i + 1], ap));
	}
	else if (s[i] == '%')
		return (1 * get_data(data, &s[i + 1], ap));
	return (1);
}
