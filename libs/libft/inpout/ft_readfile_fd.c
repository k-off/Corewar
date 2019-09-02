/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readfile_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:03:52 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 12:01:21 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile_fd(int fd)
{
	char	*str;
	char	*tmp;
	char	buf[4097];
	int		ret;

	if (fd < 0)
		return (NULL);
	str = ft_strnew(0);
	ret = read(fd, buf, 4096);
	while (ret)
	{
		buf[ret] = 0;
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
		ret = read(fd, buf, 4096);
	}
	if (ret < 0)
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (str);
}
