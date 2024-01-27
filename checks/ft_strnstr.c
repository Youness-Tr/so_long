/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:21:26 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/25 11:42:46 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// char	*ft_strnstr(const char *big, const char *little)
// {
// 	size_t	b;
// 	size_t	l;

// 	b = 0;
// 	if (!big)
// 		return (NULL);
// 	if (little[b] == '\0')
// 		return ((char *)big);
// 	while (big[b] != '\0')
// 	{
// 		l = 0;
// 		while (big[b + l] == little[l] && big[b + l] != '\0')
// 		{
// 			l++;
// 		}
// 		if (little[l] == '\0')
// 			return ((char *)&big[b]);
// 		b++;
// 	}
// 	return (NULL);
// }
