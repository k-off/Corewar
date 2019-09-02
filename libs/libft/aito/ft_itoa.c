/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 15:19:28 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/22 17:13:10 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_remal(char *str, int isneg)
{
	int		i;
	char	*res;

	res = 0;
	if (isneg < 0)
		*str = '-';
	while (!(*str == 45 || (*str > 47 && *str < 58)))
		str++;
	i = 0;
	while (str[i] != '\0')
		i++;
	res = ft_strnew(i);
	if (res)
		return (ft_strcpy(res, str));
	return (0);
}

char		*ft_itoa(long int n)
{
	char	str[12];
	char	*tmp;
	int		isneg;

	str[11] = '\0';
	tmp = &str[10];
	*tmp = '0';
	n = (int)n;
	isneg = 1;
	if (n < 0)
	{
		isneg = -1;
		n = -n;
	}
	while (n > 0)
	{
		*tmp = n % 10 + '0';
		tmp--;
		*tmp = 0;
		n /= 10;
	}
	return (ft_remal(tmp, isneg));
}
