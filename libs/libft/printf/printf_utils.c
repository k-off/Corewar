/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:00:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:01:42 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_data(t_data **data)
{
	t_data	*tmp;

	while (data[0])
	{
		tmp = (data[0])->next;
		if ((data[0])->s)
			free((data[0])->s);
		if ((data[0])->print != (data[0])->s)
			free((data[0])->print);
		free(data[0]);
		data[0] = tmp;
	}
	data[0] = 0;
}

void	print_data(t_data *data, int *d)
{
	while (data)
	{
		if (data->length)
		{
			*d += data->length;
			write(1, data->print, data->length);
		}
		data = data->next;
	}
}

void	fill_str(char *s, char c, long long len)
{
	long long	i;

	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
}

void	set_pointer_checker(char **tmp, size_t *i, unsigned long long val)
{
	if (val < 0x1ffffffff)
		*tmp = ft_strdup("100000000\0");
	else
		*tmp = ft_strdup("7fffffffffff\0");
	*i = 0;
}

void	check_pointer(char **s, char conv, unsigned long long val)
{
	char		*tmp;
	size_t		i;
	size_t		len;

	if (conv == 'p')
	{
		set_pointer_checker(&tmp, &i, val);
		len = ft_strlen(s[0]);
		if (len < ft_strlen(tmp) - 1 && s[0][0] != '0')
		{
			while (i < len)
			{
				tmp[ft_strlen(tmp) - 1 - i] = s[0][len - i - 1];
				i++;
			}
			free(s[0]);
			s[0] = ft_strdup(tmp);
		}
		else if (len == 1 && s[0][0] == '0')
		{
			free(s[0]);
			s[0] = ft_strdup("0x0\0");
		}
		free(tmp);
	}
}
