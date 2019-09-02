/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 15:38:44 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/21 12:24:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(const char *big, const char *ltl, int k, size_t ln)
{
	char		*adr;
	size_t		i;
	size_t		j;

	i = k;
	j = 0;
	adr = 0;
	while (!(big[i] == '\0' || ltl[j] == '\0')
			&& i < ln && i < ft_strlen(big))
	{
		if (big[i] == ltl[j])
		{
			if (j == 0)
				adr = (char*)&big[i];
			j++;
		}
		else
			j = 0;
		i++;
	}
	if (ltl[j] == '\0')
		return (adr);
	else
		return (0);
}

char		*ft_strnstr(const char *big, const char *ltl, size_t ln)
{
	char		*adr;
	size_t		i;

	i = 0;
	adr = 0;
	if (ltl[0] == '\0')
		return ((char*)&big[0]);
	while (adr == 0 && i < ln)
	{
		adr = ft_check(big, ltl, i, ln);
		i++;
	}
	if (big[0] == '\0' || ln < 1)
		return (0);
	else
		return (adr);
}
