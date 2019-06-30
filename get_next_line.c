/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:02:55 by mdube             #+#    #+#             */
/*   Updated: 2019/06/29 07:53:32 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static int 		checking(char **line, char **save, char *temp)
{
	int endl;

	save[fd] = ft_strsub(save[fd], (ft_strlen(*line) + endl), (ft_strlen(save[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&tmp);
	if (!(!save[fd] && !ft_strlen(*line)))
		return (1);
	else
		return (0);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save[1024];
	int				ret;
	char			*temp;
	
	if (fd < 0 || !(*line) || !(save[fd] = ft_strnew(1)))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE) > 0) && !ft_strchr(buf, '\n'))
	{
		buf[ret] = '\0';

		/*
		if (ft_strchr(buf, '\n'))
		{
			*line = (stuff up to not incl '\n');
			return (1);
			save = ft_strsub(buff, (ft_strlen(buff) - ft_strlen(temp), ft_strlen(temp));
			temp = ft_strnew(ft_strlen(buf));
		}
		*/
		temp = save[fd];
		save[fd] = ft_strjoin(save[fd], buf);
		ft_strdel(&temp);
	}
	if (ret == -1 || !(*temp == save[fd]))
	{
		if (ret == -1)
			return (-1);
		return (0);
	}
	if (ft_strchr(buf, '\n'))
		*line = lseek(fd, ret, SEEK_CUR);
	else
		*line = ft_strdup(save[fd]);
	return (checking(line, save, temp))
}
