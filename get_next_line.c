/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:38:39 by gozon             #+#    #+#             */
/*   Updated: 2024/06/04 12:05:18 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			end_of_line;

	end_of_line = 0;
	line = ft_strdup(buffer, &end_of_line);
	while (!end_of_line)
	{
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			return (free(line), NULL);
		line = ft_strjoin(&line, buffer, &end_of_line);
		if (!line)
			return (NULL);
	}
	free_buff(buffer);
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("get_next_line.h", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);

}
