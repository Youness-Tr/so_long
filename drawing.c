/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:03:06 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/14 15:24:48 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_background(t_data *data)
{
	int	x;
	int	y;
	int	posw;
	int	posh;

	x = 0;
	y = 0;
	posw = 0;
	posh = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] != '1')
				mlx_put_image_to_window (data->mlx, data->win,
					data->background, posw, posh);
			y++;
			posw += 45;
		}
		x++;
		posw = 0;
		posh += 45;
	}
}

void	draw_all(t_data *data, char *pic, int c)
{
	int	x;
	int	z;
	int	posw;
	int	posh;

	x = 0;
	z = 0;
	posw = 0;
	posh = 0;
	while (data -> map[x])
	{
		z = 0;
		while (data -> map[x][z])
		{
			if (data->map[x][z] == c)
				mlx_put_image_to_window(data->mlx, data->win,
					pic, posw, posh);
			z++;
			posw += 45;
		}
		posw = 0;
		x++;
		posh += 45;
	}
}

void	draw_player(t_data *data)
{
	if (data->position == 'u')
		mlx_put_image_to_window(data->mlx, data->win,
			data->u_player, data->posx, data->posy);
	if (data->position == 'd')
		mlx_put_image_to_window(data->mlx, data->win,
			data->pic_player, data->posx, data->posy);
	if (data->position == 'l')
		mlx_put_image_to_window(data->mlx, data->win,
			data->r_player, data->posx, data->posy);
	if (data->position == 'r')
		mlx_put_image_to_window(data->mlx, data->win,
			data->l_player, data->posx, data->posy);
}

void	draw_str(t_data *data)
{
	data->num = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx, data->win, data->map_data, 90, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map_data, 135, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map_data, 170, 0);
	mlx_string_put(data->mlx, data->win, 100, 0, 0x000000, data->num);
	free(data->num);
}

void	drawing(t_data *data)
{
	set_background(data);
	draw_all(data, data->map_data, '1');
	draw_all(data, data->bone, 'C');
	draw_all(data, data->door, 'E');
	draw_all(data, data->fire, 'M');
	mlx_string_put(data->mlx, data->win, 40, 0, 0x000000, "moves");
	mlx_string_put(data->mlx, data->win, 100, 0, 0x000000, data->num);
	draw_player(data);
}
