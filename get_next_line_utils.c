/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:18:18 by gozon             #+#    #+#             */
/*   Updated: 2024/06/04 11:52:08 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n' && i < BUFFER_SIZE)
		i++;
	return (i);
}

char	*ft_strdup(char *s, int *eol)
{
	char	*copy;
	int		len;
	int		i;

	len = ft_strlen(s);
	copy = malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	if (len < BUFFER_SIZE && s[i] == '\n')
	{
		*eol = 1;
		copy[i] = s[i];
	}
	else
		copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char **line, char *buffer, int *eol)
{
	char	*joined;
	int		buffer_len;
	int		i;
	int		k;

	buffer_len = ft_strlen(buffer);
	joined = malloc((buffer_len + ft_strlen(*line) + 1) * sizeof(char));
	if (!joined)
		return (free(*line), NULL);
	i = -1;
	while ((*line)[++i])
		joined[i] = (*line)[i];
	k = -1;
	while (++k < buffer_len)
		joined[i + k] = buffer[k];
	if (buffer_len < BUFFER_SIZE)
	{
		*eol = 1;
		joined[i + k] = buffer[k];
	}
	else
		joined[i + k] = '\0';
	return (joined);
}

void	free_buff(char *buffer)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	k = ft_strlen(buffer);
	while (k < BUFFER_SIZE && buffer[k])
	{
		buffer[i] = buffer[k];
		i++;
		k++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

// #include <stdio.h>

// ft_strlen
/*
int	main(void)
{
	printf("String normale : %i\n", ft_strlen("Bonjour"));
	printf("String avec eol : %d\n", ft_strlen("Bonjour\n blablabla"));
	printf("String > buffer : %i", ft_strlen("Bonjour bonjour !"));
	return (0);
}
*/

// ft_strdup
/*
int	main(void)
{
	int	eol;

	eol = 0;
	printf("%s %d\n", ft_strdup("Normal", &eol), eol);
	printf("%s %d\n", ft_strdup("EOL\n", &eol), eol);
	return (0);
}
*/

// ft_strjoin

/*
int	main(void)
{
	int		eol;
	char	*line = "Je suis une string";

	eol = 0;
	printf("%s %i\n", ft_strjoin(&line, " test", &eol), eol);
	eol = 0;
	printf("%s %i\n", ft_strjoin(&line, "01234567891", &eol), eol);
	return (0);
}
*/

// free_buff
/*
int	main(void)
{
	char	buff[15] = "blabla\nbla";

	free_buff(buff);
	printf("%s\n", buff);
	return (0);
}
*/
