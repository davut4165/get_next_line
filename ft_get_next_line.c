/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duslu <duslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:08:02 by duslu             #+#    #+#             */
/*   Updated: 2024/12/31 20:08:02 by duslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_get_update(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	tmp = malloc(ft_strlen(str) - i + 1);
	if (!tmp)
		return (free(str), NULL);
	i++;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i] = '\n';
	res[i + 1] = '\0';
	return (res);
}

char	*ft_read(int fd, char *str)
{
	int		size;
	char	*tmp;

	size = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(str) && size != 0)
	{
		size = read(fd, tmp, BUFFER_SIZE);
		if (size == -1)
		{
			free(tmp);
			return (free(str), NULL);
		}
		tmp[size] = '\0';
		str = ft_strjoin(str, tmp);
		if (!str)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (str);
}

char	*ft_get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
		return (free(str), NULL);
	str = ft_get_update(str);
	return (line);
}