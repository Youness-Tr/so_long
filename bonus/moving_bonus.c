/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:12:12 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/21 10:08:26 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_stop(int key, int c, t_data *data, int i)
{
	if ((data->map[data->playery - 1][data->playerx] == c && key == 13)
		|| (data->map[data->playery + 1][data->playerx] == c && key == 1)
		|| (data->map[data->playery][data->playerx + 1] == c && key == 2)
		|| (data->map[data->playery][data->playerx - 1] == c && key == 0))
	{
		data->move = 0;
		data->check_count = 0;
	}
	if (data->map[data->playery][data->playerx] == 'C' && i == 1)
	{
		data->map[data->playery][data->playerx] = '0';
		data->check_coins += 1;
	}
	if (c == 'E')
	{
		if (data->coins == data->check_coins && (
				(data->map[data->playery - 1][data->playerx] == c && key == 13)
			|| (data->map[data->playery + 1][data->playerx] == c && key == 1)
		|| (data->map[data->playery][data->playerx + 1] == c && key == 2)
		|| (data->map[data->playery][data->playerx - 1] == c && key == 0)))
			ft_non_error("YOU WIN!\n", data);
	}
}

void	counter(t_data *data, int c)
{
	data->position = c;
	data->moves += 1;
	ft_putnbr(data->moves);
	write(1, "\n", 1);
}

void	move(int key, t_data *data)
{
	if (data->check_count != 0 && key == 13)
	{
		data->posy -= data->move;
		counter(data, 'u');
	}
	else if (data->check_count != 0 && key == 1)
	{
		data->posy += data->move;
		counter(data, 'd');
	}
	else if (data->check_count != 0 && key == 2)
	{
		data->posx += data->move;
		counter(data, 'r');
	}
	else if (data->check_count != 0 && key == 0)
	{
		data->posx -= data->move;
		counter(data, 'l');
	}
}

void	check_c(int key, t_data *data)
{
	if ((data->map[data->playery - 1][data->playerx] == 'C' && key == 13)
		|| (data->map[data->playery + 1][data->playerx] == 'C' && key == 1)
		|| (data->map[data->playery][data->playerx + 1] == 'C' && key == 2)
		|| (data->map[data->playery][data->playerx - 1] == 'C' && key == 0))
	{
		data->check_count = 1;
		mlx_put_image_to_window(data->mlx, data->win,
			data->background, data->posx, data->posy);
	}
}

int	key_hook(int keys, t_data *data)
{
	data->playerx = data->posx / 45;
	data->playery = data->posy / 45;
	data->check_count = 1;
	data->move = 45;
	check_stop(keys, 'E', data, 1);
	check_stop(keys, '1', data, 0);
	check_lose(keys, 'M', data);
	if (data->check_count == 1)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->background, data->posx, data->posy);
	}
	move(keys, data);
	draw_str(data);
	check_c(keys, data);
	draw_player(data);
	if (keys == 53)
		ft_exit(data);
	return (0);
}
