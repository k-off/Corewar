/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ldtoa_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 16:04:06 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ldtoa.h"

void	init(long double *n, int *isneg, int *exp, int *prec)
{
	long double	tmp;

	*exp = 1;
	*isneg = 1;
	if (*n < 0.0)
	{
		*n = -*n;
		*isneg = -*isneg;
	}
	tmp = *n;
	while (tmp >= 10)
	{
		tmp /= 10;
		(*exp)++;
	}
	while (tmp < 1 && tmp > 0)
	{
		tmp *= 10;
		(*exp)--;
	}
	if (*prec < 0)
		*prec = 0;
	else if (*prec == 0)
		*prec = 6;
}

void	prepare_number(long double n, int exp, long double (*tmp)[])
{
	long double	m;
	int			t_exp;

	m = n;
	t_exp = exp;
	while (exp > 19)
	{
		n /= 10;
		exp--;
	}
	(*tmp)[1] = (uintmax_t)n;
	(*tmp)[0] = m - (*tmp)[1];
	if (t_exp > exp)
		(*tmp)[0] = 0;
}
