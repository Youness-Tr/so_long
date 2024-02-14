/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:05:33 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:51 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->map_data);
	mlx_destroy_image(data->mlx, data->pic_player);
	mlx_destroy_image(data->mlx, data->l_player);
	mlx_destroy_image(data->mlx, data->r_player);
	mlx_destroy_image(data->mlx, data->u_player);
	mlx_destroy_image(data->mlx, data->bone);
	mlx_destroy_image(data->mlx, data->door);
	mlx_destroy_image(data->mlx, data->fire);
	mlx_destroy_window(data->mlx, data->win);
	ft_error("image field to download", data);
}

void	images(t_data *data)
{
	data->img_size = 45;
	data->background = mlx_xpm_file_to_image(data->mlx,
			"./images/herb.xpm", &data->img_size, &data->img_size);
	data->map_data = mlx_xpm_file_to_image(data->mlx,
			"./images/wall.xpm", &data->img_size, &data->img_size);
	data->pic_player = mlx_xpm_file_to_image(data->mlx,
			"./images/front_zombie.xpm", &data->img_size, &data->img_size);
	data->l_player = mlx_xpm_file_to_image(data->mlx,
			"./images/zombie_left.xpm", &data->img_size, &data->img_size);
	data->r_player = mlx_xpm_file_to_image(data->mlx,
			"./images/zombie_right.xpm", &data->img_size, &data->img_size);
	data->u_player = mlx_xpm_file_to_image(data->mlx,
			"./images/back_zombie.xpm", &data->img_size, &data->img_size);
	data->bone = mlx_xpm_file_to_image(data->mlx,
			"./images/bone.xpm", &data->img_size, &data->img_size);
	data->door = mlx_xpm_file_to_image(data->mlx,
			"./images/door1.xpm", &data->img_size, &data->img_size);
	data->fire = mlx_xpm_file_to_image(data->mlx,
			"./images/fire.xpm", &data->img_size, &data->img_size);
	if (!data->background || !data->map || !data->pic_player || !data->l_player
		|| !data->r_player || !data->u_player || !data->bone || !data->door
		|| !data->fire)
		destroy_imgs(data);
}
