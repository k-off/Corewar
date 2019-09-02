/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldtoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:44:45 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 18:01:27 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_int(long double num)
{
	char			*s;
	char			*tmp;
	long long int	tmp_int;
	int				i;

	i = 0;
	tmp_int = 1;
	tmp = ft_strnew(1000);
	if (num < 0.0)
	{
		tmp[i] = '-';
		num = -num;
		i++;
	}
	while (tmp_int >= 1.0 && 999 - i >= 0)
	{
		tmp_int = (int)((num / 10 - (int)(num / 10.0)) * 10);
		tmp[999 - i] = tmp_int + '0';
		num /= 10;
		tmp_int = (long long int)((num - (long long int)(num / 10.0)));
		i++;
	}
	s = ft_strdup(&tmp[999 - i + 1]);
	free(tmp);
	return (s);
}

static void	ft_set_str(char *tmp, long double num, int prec)
{
	while (prec > 0)
	{
		prec--;
		tmp[prec] = (int)((num / 10 - (int)(num / 10.0)) * 10) + '0';
		num /= 10;
	}
}

static char	*set_dec(long double num, int prec)
{
	char	*s;
	char	*tmp;
	int		i;

	i = 0;
	num -= (long long int)num;
	while (i < prec)
	{
		num *= 10;
		i++;
	}
	tmp = ft_strnew(prec + 1);
	ft_set_str(tmp, num, prec);
	s = ft_strdup(&tmp[prec - i]);
	free(tmp);
	return (s);
}

static void	ft_round(long double *num, int prec)
{
	int		i;

	i = 0;
	while (i < prec + 1)
	{
		*num *= 10;
		i++;
	}
	if (((*num / 10 - (long long int)(*num / 10)) * 10) > 5.0)
		*num += 5.0;
	while (i > 0)
	{
		*num /= 10;
		i--;
	}
}

char		*ft_ldtoa(long double num, int prec)
{
	char	*s[8];

	s[0] = "-";
	s[1] = ".";
	if (prec == 0)
		s[1] = "";
	if (prec < 0)
		prec = 6;
	ft_round(&num, prec);
	s[2] = set_int(num);
	s[3] = set_dec(num, prec);
	if (num < 0)
		s[4] = ft_strjoin(s[0], s[2]);
	else
		s[4] = ft_strjoin("", s[2]);
	s[5] = ft_strjoin(s[4], s[1]);
	s[6] = ft_strjoin(s[5], s[3]);
	free(s[2]);
	free(s[3]);
	free(s[4]);
	free(s[5]);
	return (s[6]);
}
