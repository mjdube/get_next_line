/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:17:58 by mdube             #+#    #+#             */
/*   Updated: 2019/06/30 15:11:40 by mdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

int			get_next_line(const int fd, char **line);

# endif
