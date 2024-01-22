/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:40:29 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/22 18:22:50 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void    free_memory(char *pp, int p)
{
    int        i;
    char    *temp;

    i = 0;
    while (i < p)
    {
        temp =(pp + i);
        free(temp);
        i++;
    }
    free(pp);
    exit(1);
}

static char    ft_n_strdup(const char *s1, char c)
{
    int        i;
    char    *cpy;
    int        len;

    len = 0;
    while (s1[len] && s1[len] != c)
        len++;
    cpy = malloc(len + 1);
    if (!cpy)
        return (NULL);
    i = 0;
    while (s1[i] && c != s1[i])
    {
        cpy[i] = s1[i];
        i++;
    }
    cpy[i] = 0;
    return (cpy);
}

static int    count_words(char *str, char c)
{
    int    i;
    int    count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && c == str[i])
            i++;
        if (str[i] != 0)
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);
}

char    ft_split(char const *s, char c)
{
    char    **str;
    int        i;

    if (s == NULL)
        return (NULL);
    i = 0;
    str = malloc((count_words((char)s, c) + 1) * sizeof (char ));
    if (!str)
        free_heap(NULL);
    while (s)
    {
        while (s &&s == c)
            s++;
        if (s != 0)
        {
            str[i] = ft_n_strdup(s, c);
            if (! str[i])
                free_memory(str, i);
            i++;
        }
        while (s && *s != c)
            s++;
    }
    str[i] = 0;
    return (str);
}
