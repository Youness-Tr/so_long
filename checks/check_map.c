/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:52:18 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 18:13:48 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	check_map(t_data *data)
{
	int	i;

	data->lines = 0;
	data->buff = NULL;
	i = 0;
	while (1)
	{
		data->buff = get_next_line(data->fd);
		if (!(data->buff))
			break ;
		i = 0;
		while (data->buff[i])
		{
			if (i == 1)
				data->lines++;
			i++;
		}
		data->str = ft_strjoin(data->str, data->buff);
		free(data->buff);
	}
}

void	new_line(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (data->str[i] == '\n')
			data->newl++;
		i++;
	}
	data->map = ft_split(data->str, '\n');
	data->map_cp = ft_split(data->str, '\n');
	free(data->str);
	if (data->newl >= data->lines)
		ft_error("wa hdaaaa 3liya nl", data);
	data->width = ft_strlen(data->map[0]);
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
			ft_error ("hada ma hoowa hada", data);
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
				&& data->map[i][c] != 'E') && data->map[i] != NULL)
				ft_error ("chi haja fchkel", data);
			c++;
		}
		i++;
	}
	printf("%i\n", data->player);
	if (data->player != 1)
		ft_error("la3ib mossab", data);
	if (data->coins == 0)
		ft_error("finahowa l9ss !!!", data);
	if (data->exit != 1)
		ft_error("nari lbab !!", data);
}

void	check_wall(t_data *data)
{
	int	c;

	c = 0;
	while (data->map[0][c])
	{
		if (data->map[0][c] != '1')
			ft_error("t9ba f l7it\n", data);
		c++;
	}
	c = 0;
	data->lines -= 1;
	while (data->map[data->lines][c])
	{
		if (data->map[data->lines][c] != '1')
			ft_error("t9ba f l7it", data);
		c++;
	}
	c = 1;
	while (c < data->lines)
	{
		if (data->map[c][0] != '1'
			|| data->map[c][ft_strlen(data->map[c]) - 1] != '1')
			ft_error("t9ba f l7it", data);
		c++;
	}
}
