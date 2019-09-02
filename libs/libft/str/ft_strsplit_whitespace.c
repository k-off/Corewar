/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 12:25:48 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/17 12:54:22 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, int c)
{
	int word_count;
	int i;

	word_count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] > c && (s[i + 1] <= c || s[i + 1] == 127))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	ft_cpychars(char const *s, char *word, int start, int stop)
{
	int i;

	i = 0;
	while (start < stop)
	{
		word[i] = s[start];
		start++;
		i++;
	}
}

static char	**ft_cpwrds(char **words, char const *s, int c)
{
	int i;
	int j;
	int start;
	int stop;

	i = -1;
	j = 0;
	start = 0;
	stop = 0;
	while (s[++i] != '\0')
	{
		if (s[i] <= c || s[i] == '\0')
			start = i + 1;
		if (s[i] > c && (s[i + 1] == 127 ||
			s[i + 1] <= c))
		{
			stop = i + 1;
			words[j] = (char*)ft_memalloc(sizeof(char) * (stop - start + 1));
			ft_cpychars(s, words[j], start, stop);
			j++;
		}
	}
	words[j] = 0;
	return (words);
}

char		**ft_strsplit_whitespace(char const *s)
{
	char	**words;
	int		w_count;

	if (s)
	{
		w_count = ft_countwords(s, 32);
		words = (char**)ft_memalloc(sizeof(char*) * (w_count + 1));
		if (words)
			return (ft_cpwrds(words, s, 32));
	}
	return (0);
}
