/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldtoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ldtoa.h"

static char	*round_up(char *s)
{
	size_t		len;
	char		*tmp;
	char		c;

	len = ft_strlen(s);
	c = s[0];
	while (len > 0)
	{
		len--;
		s[len]++;
		if (s[len] == 58)
			s[len] -= 10;
		else if (s[len] == 47)
			s[len]--;
		else
			break ;
	}
	if (s[0] == 48 && c == 57)
		tmp = ft_strjoin("1", s);
	else
		tmp = ft_strdup(s);
	free(s);
	return (tmp);
}

static char	*get_value(long double n[], int exp, int pr)
{
	char	*s[2];

	if (!(n[1] > 0))
		s[1] = ft_strdup("0\0");
	else
		s[1] = (char*)ft_memalloc(sizeof(char) * exp + 1);
	while (exp >= 0)
	{
		exp--;
		if (exp >= 19)
			s[1][exp] = 48;
		else
		{
			s[1][exp] = (uintmax_t)n[1] % 10 + 48;
			n[1] = (uintmax_t)(n[1] / 10);
		}
	}
	if (n[0] >= 0.5 && pr < 1)
		return (round_up(s[1]));
	if (pr > 0)
		s[0] = ft_strjoin(s[1], ".");
	else
		s[0] = ft_strdup(s[1]);
	free(s[1]);
	return (s[0]);
}

static char	*set_decimal(long double n[], int exp, int pr)
{
	int		i;
	char	*s[3];

	if (pr < 1)
		return (get_value(n, exp, pr));
	i = 0;
	s[2] = (char*)ft_memalloc(sizeof(char) * pr + 1);
	while (i < pr)
	{
		s[2][i] = (uintmax_t)(n[0] * 10) + 48;
		n[0] = n[0] * 10 - (uintmax_t)(n[0] * 10);
		i++;
	}
	s[1] = get_value(n, exp, pr);
	s[0] = ft_strjoin(s[1], s[2]);
	free(s[1]);
	free(s[2]);
	if (n[0] >= 1.0 / 2)
		return (round_up(s[0]));
	return (s[0]);
}

static char	*null_str(long double n, int precision)
{
	char	*s;
	char	*tmp;

	tmp = 0;
	if (precision == 0 && 1 / n < 0)
		return (ft_strdup("-0"));
	if (precision == 0)
		return (ft_strdup("0"));
	if (1 / n < 0)
		tmp = ft_strdup("-0.");
	else if (1 / n > 0)
		tmp = ft_strdup("0.");
	s = 0;
	while (precision)
	{
		s = ft_strjoin(tmp, "0");
		free(tmp);
		tmp = s;
		precision--;
	}
	return (s);
}

char		*ft_ldtoa(long double n, int precision)
{
	long double	tmp[2];
	int			isneg;
	int			exponent;
	char		*tmp_s;
	char		*str;

	init(&n, &isneg, &exponent, &precision);
	prepare_number(n, exponent, &tmp);
	if ((exponent < 0 && exponent < -precision) || n == 0)
		return (null_str(n, precision));
	tmp_s = set_decimal(tmp, exponent, precision);
	if (isneg < 0)
		str = ft_strjoin("-", tmp_s);
	else
		str = ft_strdup(tmp_s);
	free(tmp_s);
	return (str);
}
