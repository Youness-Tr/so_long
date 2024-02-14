/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:19:49 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/14 15:35:28 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
	void	*door;
	void	*fire;
	int		position;
	int		img_size;
	int		posx;
	int		posy;
	int		move;
	int		fd;
	int		flood_i;
	int		flood_c;
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
	int		moves;
	char 	*num;
}	t_data;

/*********** parsing **********/

/* libft */

char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putnbr(int n);
void	ft_putchar(char c);


/* checking */

int		check_path(char *argv);
void	ft_checks(t_data *data, char *argv);
void	check_map(t_data *data);
void	new_line(t_data *data);
void	check_char(t_data *data, int i, int c);
void	chars(t_data *data, int i, int c);
void	check_wall(t_data *data);


/* flood_fill */

void	floodfill_check(t_data *data);
void	f_floodfill(char **map, int x, int z, t_data *data);

/* errors */

void	ft_error(char *str, t_data *data);
void 	ft_error_one(char *str);
void	ft_non_error(char *str, t_data *data);

/*********** graphic **********/

/* images */

void	images(t_data *data);
void	destroy_imgs(t_data *data);
int 	ft_exit(t_data *data);
void	free_map(char **map);

/* drawing */

void	set_background(t_data *data);
void	draw_all(t_data *data, char *pic, int c);
void	draw_player(t_data *data);
void 	draw_str(t_data *data);
void 	drawing(t_data *data);

/* moving */

int		key_hook(int keys, t_data *data);
void	check_stop(int key, int c, t_data *data, int i);
void	move(int key, t_data *data);
void	check_c(int key, t_data *data);
void	check_lose(int key, int c, t_data *data);

/*get_next_line*/

char	*get_next_line(int fd);
char	*read_file(int fd, char *save);
char	*gtline(char *save, int i);
char	*new_one(char *save, int i, int j);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *save, char *buff);
int		ft_strlen(const char *s);

#endif