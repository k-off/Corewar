/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:35:57 by pacovali      #+#    #+#                 */
/*   Updated: 2019/02/04 11:44:55 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_line(char **line, char **lines, int i)
{
	int				j;

	j = i;
	if (i == -1)
		return (-1);
	i = 0;
	line[0] = ft_strdup(lines[0]);
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	if (line[0][i] != '\n' && j != -2)
	{
		free(line[0]);
		return (0);
	}
	free(lines[0]);
	if (line[0][i] == '\n')
		lines[0] = ft_strdup(&(line[0][i + 1]));
	else
		lines[0] = ft_strdup("\0");
	line[0][i] = '\0';
	if (ft_strlen(line[0]) == 0 && ft_strlen(lines[0]) == 0 && j == -2)
		return (0);
	return (1);
}

int			ft_set_line(int fd, char **lines)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	long			r;
	int				i;

	r = 1;
	while (r != 0)
	{
		r = (long)read(fd, buf, BUFF_SIZE);
		if (r < 0)
			return (-1);
		buf[r] = 0;
		i = 0;
		tmp = lines[0];
		lines[0] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	if (r == 0)
		return (-2);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static	char	**lines;
	int				gl_ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!lines)
		lines = (char**)ft_memalloc(sizeof(char*) * 1001);
	if (lines[fd] == 0)
		lines[fd] = ft_strdup("\0");
	gl_ret = ft_get_line(line, &lines[fd], 0);
	if (gl_ret == 0)
		gl_ret = ft_get_line(line, &(lines[fd]), ft_set_line(fd, &(lines[fd])));
	if (gl_ret > 0)
		return (1);
	else if (gl_ret < 0)
		return (-1);
	return (0);
}
