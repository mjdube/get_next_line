/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:02:55 by mdube             #+#    #+#             */
/*   Updated: 2019/07/03 16:17:09 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"

static int			checknewline(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char			*beforenewline(const char *s)
{
	size_t			i;
	char			*fresh;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			break;
		i++;
	}
	fresh = (char *)ft_memalloc(sizeof(char) * i);
	fresh = ft_strncpy(fresh, s, i);
	return (fresh);
}

static char			*afternewline(char *s)
{
	char			*fresh;
	
	fresh = ft_strchr(s, '\n');
	return (++fresh);
}

static int			newline(char **s, char **line, int fd)
{
	int				i;
	
	i = 0;
	while (s[fd][i] != '\n' || s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		ft_strdel(&s[fd]);
		return (1);
	}
	else if (s[fd][i] ==  '\0')
		*line = afternewline(s[fd]);
	ft_strdel(&s[fd]);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*s[MAX_FD];
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	
	if (fd < 0 || !*(line) || (ret = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	while (ret  > 0 && (checknewline(s[fd]) == 0))
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
	if (checknewline(s[fd]) == 1)
		*line = beforenewline(s[fd]);
	return (newline(s, line, fd));
}
