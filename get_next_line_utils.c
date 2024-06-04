/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozon <gozon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:18:18 by gozon             #+#    #+#             */
/*   Updated: 2024/06/04 08:26:39 by gozon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n' && i < BUFFERSIZE)
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
	}
	if (!s[i] || s[i] == '\n')
		*eol = 1;
	copy[i] = s[i];
	return (copy);
}
