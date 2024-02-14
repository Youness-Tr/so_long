/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:33:12 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:01 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, t_data *data)
{
	write(2, str, ft_strlen(str));
	free_map(data->map);
	free_map(data->map_cp);
	system("leaks so_long");
	exit(1);
}

void	ft_non_error(char *str, t_data *data)
{
	write(1, str, ft_strlen(str));
	free_map(data->map);
	free_map(data->map_cp);
	system("leaks so_long");
	ft_exit(data);
}

void	ft_error_one(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	ft_exit(t_data *data)
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
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
