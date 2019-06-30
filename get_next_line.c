/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:02:55 by mdube             #+#    #+#             */
/*   Updated: 2019/06/30 15:42:39 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static int			checknewline(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*afternewline(const char *buf)
{
	size_t		i;
	char	*fresh;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break;
		i++;
	}
	fresh = ft_strnew(i);
	fresh = ft_strncpy(fresh, buf, i);
	return (fresh);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[4096];
	int				ret;
	char			buf[BUFFER_SIZE + 1];

	if (fd < 0 || !*(line))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 && (checknewline(buf) == 0))
	{
		buf[ret] = '\0';
		s[fd] = buf;
	}
	if (ret == -1)
		return (-1);
	if (checknewline(buf) == 1)
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
	else
		*line = ft_strdup(s[fd]);
	s[fd] = afternewline(*line);
	return (!(!s[fd] && !ft_strlen(*line)));
}
