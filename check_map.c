/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:52:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/15 14:54:05 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_data *data)
{
	int	i;
	int	check;

	check = 0;
	data->lines = 0;
	data->buff = NULL;
	i = 0;
	while (1)
	{
		data->buff = get_next_line(data->fd);
		if (!data->buff && !check)
			ft_error_one("map doesnt exist");
		if (!data->buff)
			break ;
		data->str = ft_strjoin(data->str, data->buff);
		free(data->buff);
		check++;
	}
}

void	new_line(t_data *data)
{
	int	i;

	i = 0;
	data->newl = 0;
	data->lines = 0;
	while (data->str[i])
	{
		if (data->str[i] == '\n')
			data->newl++;
		i++;
	}
	data->map = ft_split(data->str, '\n');
	data->map_cp = ft_split(data->str, '\n');
	i = 0;
	while (data->map[i])
	{
		data->lines++;
		i++;
	}
	free(data->str);
	if (data->lines < 3)
		ft_error("resize your map", data);
	if (!(data->newl == data->lines - 1))
		ft_error("new line error", data);
	data->width = ft_strlen(data->map[0]);
}

void	check_wall(t_data *data)
{
	int	c;

	c = 0;
	while (data->map[0][c])
	{
		if (data->map[0][c] != '1')
			ft_error("resize your map\n", data);
		c++;
	}
	c = 0;
	data->lines -= 1;
	while (data->map[data->lines][c])
	{
		if (data->map[data->lines][c] != '1')
			ft_error("resize your map", data);
		c++;
	}
	c = 1;
	while (c < data->lines)
	{
		if (data->map[c][0] != '1'
			|| data->map[c][ft_strlen(data->map[c]) - 1] != '1')
			ft_error("resize your map", data);
		c++;
	}
}

void	check_char(t_data *data, int i, int c)
{
	while (data->map[i])
	{
		c = 0;
		while (data->map[i][c])
		{
			if (data->map[i][c] == 'P')
			{
				data->player += 1;
				data->playerx = c;
				data->playery = i;
			}
			if (data->map[i][c] == 'C')
				data->coins += 1;
			if (data->map[i][c] == 'E')
				data->exit += 1;
			c++;
		}
		if ((ft_strlen(data->map[i]) != ft_strlen(data->map[i + 1]))
			&& data->map[i + 1])
			ft_error ("resize your map", data);
		i++;
	}
}

void	chars(t_data *data, int i, int c)
{
	while (data->map[i])
	{
		c = 0;
		while (data->map[i][c])
		{
			if ((data->map[i][c] != '1' && data->map[i][c] != '0'
				&& data->map[i][c] != 'P' && data->map[i][c] != 'C'
				&& data->map[i][c] != 'E' && data->map[i][c] != 'M'))
				ft_error ("something added !!", data);
			c++;
		}
		i++;
	}
	if (data->player != 1)
		ft_error("player not correct", data);
	if (data->coins == 0)
		ft_error("coins not correct", data);
	if (data->exit != 1)
		ft_error("exit not correct", data);
}
