/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:08:52 by gozon             #+#    #+#             */
/*   Updated: 2024/06/05 12:26:29 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v2.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;
	int			eol;

	if (!buf)
		return (NULL);
	eol = 0;
	line = malloc(sizeof(char));
	if (line)
		line[0] = '\0';
	else
		return (NULL);
	while (!eol)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (free(line), NULL);
		line = ft_strjoin(&line, buf, &eol);
		if (!line)
			return (NULL);
		if (read_size < BUFFER_SIZE)
			return (free(buf), line);
	}
	return (ft_trimbuf(buf), line);
}
