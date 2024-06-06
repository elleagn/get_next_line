/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_v2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:19:17 by gozon             #+#    #+#             */
/*   Updated: 2024/06/06 08:41:14 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v2.h"

int	ft_get_last_byte(char *buf)
{
	int	i;

	i = 0;
	while (buf[i + 1] && buf[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **line, char *buf, int *eol)
{
	int		len;
	int		last_byte;
	char	*joined;
	int		i;

	if (!buf[0])
		return (*line);
	len = ft_strlen(*line);
	last_byte = ft_get_last_byte(buf);
	if (buf[last_byte] == '\n')
		*eol = 1;
	joined = malloc(len + (last_byte + 1) + 1);
	if (!joined)
		return (free(*line), NULL);
	i = -1;
	while (++i < len)
		joined[i] = (*line)[i];
	while (i <= len + last_byte)
	{
		joined[i] = buf[i - len];
		i++;
	}
	joined[i] = '\0';
	return (free(*line), joined);
}

void	ft_trimbuf(char *buf)
{
	int	i;
	int	k;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i])
		i++;
	k = 0;
	while (buf[i])
	{
		buf[k] = buf[i];
		i++;
		k++;
	}
	while (buf[k])
	{
		buf[k] = '\0';
		k++;
	}
}
#include <stdio.h>

// ft_strjoin

/*
int	main(void)
{
	char	*s;
	int		eol;

	eol = 0;
	s = calloc(1, sizeof(char));
	printf("%s %d\n", ft_strjoin(&s, "Null line", &eol), eol);
	eol = 0;
	s = calloc(1, sizeof(char));
	printf("%s %d\n", ft_strjoin(&s, "", &eol), eol);
	eol = 0;
	s = calloc(1, sizeof(char));
	printf("%s %d\n", ft_strjoin(&s, "eol at the end\n", &eol), eol);
	eol = 0;
	s = calloc(1, sizeof(char));
	printf("%s %d\n", ft_strjoin(&s, "eol in the \n middle", &eol), eol);
	return (0);
}
*/

/*
int	main(void)
{
	char	buf1[] = "I'm in the middle of the \n file";
	char	buf2[] = "I'm the end of the file";
	char	buf3[] = "I'm the end of a line";

	ft_trimbuf(buf1);
	ft_trimbuf(buf2);
	ft_trimbuf(buf3);
	printf("%s", buf1);
	printf("%s", buf2);
	printf("%s", buf3);
	return (0);
}
*/
