/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:26:35 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/21 10:08:02 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	int	n_len(long n)
{
	long	result;
	int		i;

	i = 0;
	result = n;
	while (result != 0)
	{
		result = result / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	result;
	char	*str;

	i = 0;
	if (n <= 0)
		i++;
	i += n_len(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	result = (long)n;
	str[i] = '\0';
	if (result < 0)
		result *= -1;
	while (i)
	{
		str[--i] = result % 10 + 48;
		result /= 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
