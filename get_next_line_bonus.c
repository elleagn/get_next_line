/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:34:12 by gozon             #+#    #+#             */
/*   Updated: 2024/06/07 13:13:37 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[1025][BUFFER_SIZE + 1];
	char		*line;
	int			read_size;
	int			eol;

	eol = 0;
	line = ft_init_line(buf[fd], fd, &read_size);
	if (!line)
		return (NULL);
	while (!eol)
	{
		line = ft_strjoin(&line, buf[fd], &eol, read_size);
		if (!line)
			return (NULL);
		if (!eol)
		{
			read_size = read(fd, buf[fd], BUFFER_SIZE);
			if (read_size == -1)
				return (free(line), NULL);
			if (read_size == 0)
				eol = 1;
		}
	}
	ft_trimbuf(buf[fd], read_size);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	char	*line1;
	int		fd2;
	char	*line2;

	fd1 = open("get_next_line.h", O_RDONLY);
	line1 = get_next_line(fd1);
	fd2 = open("get_next_line.c", O_RDONLY);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);
		printf("%s", line2);
		free(line2);
		line2 = get_next_line(fd2);
	}
	free(line1);
	free(line2);
	return (0);
}
*/
