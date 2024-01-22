/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:10:30 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/18 12:55:26 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *save);
char	*gtline(char *save, int i);
char	*new_one(char *save, int i, int j);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *save, char *buff);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif