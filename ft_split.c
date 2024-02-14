/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:40:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/13 14:09:58 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	wc;
	int	new;

	i = 0;
	wc = 0;
	new = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			new = 0;
		else if (new == 0)
		{
			new = 1;
			wc++;
		}
		i++;
	}
	return (wc);
}

static int	check_free(char **array, int j)
{
	if (array[j] == NULL)
	{
		while (j)
			free(array[j--]);
		free(array);
		return (1);
	}
	return (0);
}

static char	*arrays(const char **s, char c)
{
	int		countll;
	int		i;
	char	*str;

	i = 0;
	countll = 0;
	while ((*s)[i] && (*s)[i] != c)
	{
		countll++;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (countll + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((*s)[i] && i < countll)
	{
		str[i] = (*s)[i];
		i++;
	}
	str[i] = '\0';
	while (i--)
		(*s)++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		wc;
	int		j;

	if (s == NULL)
		return (NULL);
	j = 0;
	wc = count_words((char *)s, c);
	p = malloc(sizeof(char *) * (wc + 1));
	if (!p)
		return (NULL);
	while (*s && j < wc)
	{
		if (*s != c)
		{
			p[j] = arrays(&s, c);
			if (check_free(p, j))
				return (NULL);
			j++;
		}
		s++;
	}
	p[wc] = 0;
	return (p);
}
