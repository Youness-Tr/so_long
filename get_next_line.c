/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:06:48 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/09 14:46:05 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = malloc((size_t)(BUFFER_SIZE) * sizeof(char) + 1);
	if (!buff)
	{
		free(save);
		return (NULL);
	}
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	save = read_file(fd, save);
	if (save == NULL)
		return (NULL);
	line = gtline(save, 0);
	if (!line)
	{
		free(save);
		save = NULL;
	}
	save = new_one(save, 0, 0);
	return (line);
}
