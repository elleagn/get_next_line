/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:38:39 by gozon             #+#    #+#             */
/*   Updated: 2024/06/03 13:26:30 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFERSIZE];
	char		*line;
	int			end_of_line;

	end_of_line = 0;
	line = ft_strdup(buffer, &end_of_line);
	while (!end_of_line)
	{
		if (ft_update_buffer(buffer, fd) == -1)
			return (free(line), NULL);
		line = ft_strlcat(line, buffer);
		if (!line)
			return (NULL);
	}
	free_buff(buffer);
	return (line);
}
