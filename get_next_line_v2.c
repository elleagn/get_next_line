/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:08:52 by gozon             #+#    #+#             */
/*   Updated: 2024/06/06 09:54:46 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v2.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;
	int			eol;

	eol = 0;
	line = malloc(sizeof(char));
	if (line)
		line[0] = '\0';
	else
		return (NULL);
	while (!eol)
	{
		line = ft_strjoin(&line, buf, &eol);
		if (!eol)
			read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(line), NULL);
		if (!line)
			return (NULL);
		if (read_size == 0)
			eol = 1;
	}
	ft_trimbuf(buf);
	return (line);
}

// #include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("get_next_line_v2.h", O_RDONLY);
	line = get_next_line(fd);
	while (line[0])
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
