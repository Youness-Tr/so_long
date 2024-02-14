/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:52:08 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/14 15:07:50 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*p;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < len && s[i])
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	while (big[b] != '\0' && b < len)
	{
		l = 0;
		while (big[b + l] == little[l] && big[b + l] != '\0' && (b + l < len))
		{
			l++;
		}
		if (little[l] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}

void	ft_putnbr(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr((num / 10));
	ft_putchar((num % 10 + 48));
}
