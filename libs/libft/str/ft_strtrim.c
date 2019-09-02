/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 10:49:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:46:53 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char *dst, char const *s, int start, int stop)
{
	if (dst)
		return (ft_strncpy(dst, &s[start], stop - start));
	return (0);
}

static void	find_start_stop(char const *s, int i, int *start, int *stop)
{
	int		f;

	f = 0;
	while (s[i] != 0)
	{
		if ((i == 0 && !ft_isspace(s[i])) || (!f && !ft_isspace(s[i]) \
										&& ft_isspace(s[i - 1])))
		{
			*start = i;
			f = 1;
		}
		if (f && (s[i + 1] == 0 || ft_isspace(s[i + 1])) && !ft_isspace(s[i]))
			*stop = i + 1;
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		start;
	int		stop;

	if (!s)
		return (0);
	dst = 0;
	i = 0;
	start = 0;
	stop = 0;
	find_start_stop(s, i, &start, &stop);
	dst = ft_strnew(stop - start);
	return (check(dst, s, start, stop));
}
