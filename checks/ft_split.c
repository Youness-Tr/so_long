/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:40:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/11 15:07:20 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// static void	free_memory(char **pp, int p)
// {
// 	int		i;
// 	char	*temp;

// 	i = 0;
// 	while (i < p)
// 	{
// 		temp = *(pp + i);
// 		free(temp);
// 		i++;
// 	}
// }

// static int	check_free(char **array, int j)
// {
// 	if (array[j] == NULL)
// 	{
// 		while (j)
// 			free(array[j--]);
// 		free(array);
// 		return (1);
// 	}
// 	return (0);
// }

// static char	*ft_n_strdup(const char *s, char c)
// {
// 	int		i;
// 	char	*cpy;
// 	int		countll;

// 	countll = 0;
// 	while (s1[countll] && s1[countll] != c)
// 		countll++;
// 	cpy = malloc(countll + 1);
// 	if (!cpy)
// 		return (0);
// 	i = 0;
// 	while (s1[i] && i < countll)
// 	{
// 		cpy[i] = s1[i];
// 		i++;
// 	}
// 	cpy[i] = 0;
// 	return (cpy);
// }

// static int	count_words(char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && c == str[i])
// 			i++;
// 		if (str[i] != 0)
// 			count++;
// 		while (str[i] && str[i] != c)
// 			i++;
// 	}
// 	return (count);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str;
// 	int		i;

// 	if (s == NULL)
// 		return (NULL);
// 	i = 0;
// 	str = malloc((count_words((char *)s, c) + 1) * sizeof (char *));
// 	if (str == NULL)
// 		return (NULL);
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s != 0)
// 		{
// 			str[i] = ft_n_strdup(s, c);
// 			if (! str[i])
// 				free_memory(str, i);
// 			i++;
// 		}
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	str[i] = 0;
// 	return (str);
// }




int main()
{
	int i = 0;

	char str[] = "    hello come     cool ok    ";
	char **split;

	split = ft_split(str, ' ');

	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
