/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:30:01 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/21 10:08:31 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_lose(int key, int c, t_data *data)
{
	if ((data->map[data->playery - 1][data->playerx] == c && key == 13)
		|| (data->map[data->playery + 1][data->playerx] == c && key == 1)
		|| (data->map[data->playery][data->playerx + 1] == c && key == 2)
		|| (data->map[data->playery][data->playerx - 1] == c && key == 0))
	{
		ft_non_error("YOU LOSE !!", data);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
