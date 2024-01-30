/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:18:49 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 16:38:10 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	f_floodfill(char **map, int x, int z, t_data *data)
{
	if (x < 0 || x >= data->lines || z < 0 || z >= (ft_strlen(map[0]))
		|| map[x][z] == '1' || map[x][z] == 'H')
	{
		return ;
	}
	if (map[x][z] == 'E')
	{
		map[x][z] = '1';
		return ;
	}
	map[x][z] = 'H';
	f_floodfill(map, x -1, z, data);
	f_floodfill(map, x +1, z, data);
	f_floodfill(map, x, z -1, data);
	f_floodfill(map, x, z +1, data);
}

void	floodfill_check(t_data *data)
{
	data->i = 0;
	f_floodfill(data->map_cp, data->playery, data->playerx, data);
	while (data->map_cp[data->i])
	{
		data->c = 0;
		while (data->map_cp[data->i][data->c])
		{
			if (data->map_cp[data->i][data->c] == 'C'
				|| data->map_cp[data->i][data->c] == 'E')
				ft_error("ch9itiha !!!", data);
			data->c++;
		}
		data->i++;
	}
}

void	ft_error(char *str, t_data *data)
{
	write(2, str, ft_strlen(str));
	free(data->map);
	free(data->map_cp);
	exit(1);
}
