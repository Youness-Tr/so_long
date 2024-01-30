/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:33:04 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 17:26:38 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	if (c == '\0')
		return ((char *)&save[ft_strlen(save)]);
	while (save[i])
	{
		if (save[i] == (char)c)
			return ((char *)&save[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buff)
{
	int		len1;
	int		len2;
	char	*str;

	str = malloc(((ft_strlen(save) + ft_strlen(buff)) + 1) * sizeof(char));
	if (!str)
	{
		free(save);
		return (NULL);
	}
	len2 = 0;
	len1 = 0;
	while (save && save[len1] != '\0')
	{
		str[len1] = save[len1];
		len1++;
	}
	while (buff[len2] != '\0')
	{
		str[len1 + len2] = buff[len2];
		len2++;
	}
	str[len1 + len2] = '\0';
	free(save);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*gtline(char *save, int i)
{
	char	*str;

	if (!ft_strlen(save))
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_one(char *save, int i, int j)
{
	char	*str;

	if (save == NULL)
		return (NULL);
	if (!save[i])
		return (free(save), NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	str = malloc(((ft_strlen(save) - i) * sizeof(char)) + 1);
	if (!str)
		return (free(save), NULL);
	while (save[i + j] != '\0')
	{
		str[j] = save[i + j];
		j++;
	}
	free(save);
	str[j] = '\0';
	return (str);
}
