/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:30:01 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/21 10:36:43 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(char *argv)
{
	char	*str;
	int		len;

	len = ft_strlen(argv);
	if (len > 4 && (ft_strnstr(argv, "/.", len) == NULL))
	{
		str = ft_substr(argv, (len - 4), 4);
		if ((ft_strncmp(str, ".ber")) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

void	ft_checks(t_data *data, char *argv)
{
	data->check_coins = 0;
	data->player = 0;
	data->coins = 0;
	data->exit = 0;
	data->num = "0";
	data->check_coins = 0;
	data->fd = open(argv, O_RDWR);
	if (data->fd < 0)
		ft_error_one("can't open file");
	check_map(data);
	new_line(data);
	check_wall(data);
	check_char(data, 0, 0);
	chars(data, 0, 0);
	floodfill_check(data);
	data->lines += 1;
	data->position = 'd';
	data->posy = data->playery * 45;
	data->posx = data->playerx * 45;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
