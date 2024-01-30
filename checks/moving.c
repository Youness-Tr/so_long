/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:12:12 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 18:21:53 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_stop(int key, int c, t_data *data, int i)
{
	if (c == 'E')
	{
		if (data->coins == data->check_coins && (
				(data->map[data->playery - 1][data->playerx] == c && key == 126)
			|| (data->map[data->playery + 1][data->playerx] == c && key == 125)
		|| (data->map[data->playery][data->playerx + 1] == c && key == 124)
		|| (data->map[data->playery][data->playerx - 1] == c && key == 123)))
		{
			ft_error("YOU WIN!\n", data);
		}
	}
	if ((data->map[data->playery - 1][data->playerx] == c && key == 126)
		|| (data->map[data->playery + 1][data->playerx] == c && key == 125)
		|| (data->map[data->playery][data->playerx + 1] == c && key == 124)
		|| (data->map[data->playery][data->playerx - 1] == c && key == 123))
	{
		data->move = 0;
		data->check_count = 0;
	}
	if (data->map[data->playery][data->playerx] == 'C' && i == 1)
	{
		data->map[data->playery][data->playerx] = '0';
		data->check_coins += 1;
		printf("check coins is %i and %i\n", data->check_coins, data->coins);
	}
}

void	move(int key, t_data *data)
{
	if (data->check_count != 0 && key == 126)
	{
		data->posy -= data->move;
		data->position = 'u';
	}
	else if (data->check_count != 0 && key == 125)
	{
		data->posy += data->move;
		data->position = 'd';
	}
	else if (data->check_count != 0 && key == 124)
	{
		data->posx += data->move;
		data->position = 'r';
	}
	else if (data->check_count != 0 && key == 123)
	{
		data->posx -= data->move;
		data->position = 'l';
	}
}
void check_C(int key, t_data *data)
{
	if ((data->map[data->playery - 1][data->playerx] == 'C' && key == 126)
		|| (data->map[data->playery + 1][data->playerx] == 'C' && key == 125)
		|| (data->map[data->playery][data->playerx + 1] == 'C' && key == 124)
		|| (data->map[data->playery][data->playerx - 1] == 'C' && key == 123))
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
	if (data->check_count == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->background, data->posx, data->posy);
	move(keys, data);
	check_C(keys, data);
	draw_player(data);
	if (keys == 53)
		exit(0);
	return (0);
}
