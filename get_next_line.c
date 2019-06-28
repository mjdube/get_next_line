/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:02:55 by mdube             #+#    #+#             */
/*   Updated: 2019/06/27 17:35:31 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	int				ret;
	size_t			i;
	char			*temp;
	
	if (fd < 0 || !(*line) || ret = read(fd, NULL, 0) < 0)
		return (-1);
	
	while (ret = read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			*line = (stuff up to not incl '\n');
			return (1);
			temp = ft_strchr(buf, '\n')
			save = ft_strsub(buff, (ft_strlen(buff) - ft_strlen(temp), ft_strlen(temp));
		temp = ft_strnew(ft_strlen(buf));

	}
}
