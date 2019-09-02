/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtoll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:44:45 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 18:01:27 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		check_base(char **str, int *base)
{
	if (*base < 0 || *base == 1 || *base > 36)
		*base = 0;
	if (*base == 0 && str[0][0] == '0' &&
		(str[0][1] == 'x' || str[0][1] == 'X'))
	{
		*base = 16;
		str[0] += 2;
	}
	else if (*base == 0 && str[0][0] == '0' &&
			(str[0][1] == 'x' || str[0][1] == 'X'))
	{
		*base = 8;
		str[0]++;
	}
	else if (*base == 0 && str[0][0] != '0')
		*base = 10;
}

static void		check_sign(char **str, int *sign, int *base)
{
	sign[0] = 1;
	if (str[0][0] == '-')
	{
		sign[0] = -1;
		str[0]++;
	}
	else if (str[0][0] == '+')
		str[0]++;
	check_base(str, base);
}

static int		get_num(char c, int base)
{
	int		res;

	if (ft_isupper(c))
		res = (c - 65) + 10;
	else if (ft_islower(c))
		res = (c - 97) + 10;
	else
		res = (c - 48);
	if (res >= base)
		return (-1);
	return (res);
}

long long int	ft_strtoll(const char *str, char **endptr, int base)
{
	int				i;
	long long int	res;
	int				curr;
	int				sign;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	check_sign((char**)&str, &sign, &base);
	while (ft_isalnum(str[i]))
	{
		curr = get_num(str[i], base);
		if (curr >= 0)
			res = (res * base + curr);
		else
			break ;
		i++;
	}
	if (endptr)
		*endptr = (char*)&str[i];
	return (res * sign);
}
