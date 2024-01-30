/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:19:49 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 18:11:24 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_data
{
	char	*buff;
	char	*str;
	char	**map;
	char	**map_cp;
	void	*mlx;
	void	*win;
	void	*background;
	void	*map_data;
	void	*pic_player;
	void	*l_player;
	void	*r_player;
	void	*u_player;
	void	*bone;
	void	*hole;
	int		position;
	int		img_size;
	int		posx;
	int		posy;
	int		move;
	int		fd;
	int		i;
	int		c;
	int		player;
	int		coins;
	int		exit;
	int		newl;
	int		lines;
	int		width;
	int		playerx;
	int		playery;
	int		check_count;
	int		check_coins;
	int		x;
	int		y;
}	t_data;

/*********** parsing **********/

/* checking */

void	check_map(t_data *data);
void	new_line(t_data *data);
void	check_char(t_data *data, int i, int c);
void	chars(t_data *data, int i, int c);
void	check_wall(t_data *data);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little);

/* flood_fill */

void	floodfill_check(t_data *data);
void	f_floodfill(char **map, int x, int z, t_data *data);
void	ft_error(char *str, t_data *data);

/*********** graphic **********/

/* images */

void	images(t_data *data);
void	destroy_imgs(t_data *data);

/* drawing */

void	set_background(t_data *data);
void	draw_all(t_data *data, char *pic, int c);
// void	draw_map(t_data *data);
// void	draw_coins(t_data *data);
void	draw_player(t_data *data);

/* moving */

int		key_hook(int keys, t_data *data);
void	check_stop(int key, int c, t_data *data, int i);
void	move(int key, t_data *data);

#endif