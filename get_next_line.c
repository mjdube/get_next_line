/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:02:55 by mdube             #+#    #+#             */
/*   Updated: 2019/07/02 17:58:29 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static int			checknewline(char **s, int fd)
{
	int		i;

	i = 0;
	while (s[fd][i])
	{
		if (s[fd][i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*beforenewline(const char **s, int fd)
{
	size_t		i;
	char	fresh[MAX_FD];

	i = 0;
	while (s[fd][i])
	{
		if (s[fd][i] == '\n')
			break;
		i++;
	}
	fresh = ft_strncpy(fresh, s[fd], i - 1);
	return (fresh);
}

static char		*afternewline(char **s, int fd)
{
	char *fresh;

	fresh = ft_strchr(s[fd][i], '\n');
	return (++fresh);
}

static int		newline(char **s, char **line, int fd, int ret)
{
	char *temp;

	temp = ft_strdup(s[fd]);

}

int					get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*temp;

	if (fd < 0 || !*(line) || (ret = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	while (ret  > 0 && (checknewline(s[fd], fd) == 0))
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = temp;
	}
    if (ret < 0)
        return (-1);
    else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
        return (0);
	if (checknewline(s, fd) == 0)
		*line = beforenewline(s, fd);
	else
		*line = ft_strdup(s[fd]);
    return (newline(s, line, fd, ret));
}
