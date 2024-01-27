#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct	s_data {
	char	*buff;
	char	*str;
	char	**map;
	char	**map_cp;
	int		fd;
	int		i;
	int		c;
    int 	x;
    int 	y;
	int 	player;
	int		coins;
	int		exit;
	int		newl;
	int		lines;
	int		width;
	int 	posx;
	int 	posy;
}				t_data;

typedef struct	s_info {
	void	*mlx;
	void	*win;
	void	*background;
	void	*map_graph;
	void	*player;
	int 	img_size;
    int 	x;
    int 	y;
}				t_info;

void check_map(t_data *data);
void new_line(t_data *data);
void check_char(t_data *data);
void check_wall(t_data *data);
void floodfill_check(t_data *data);
void f_floodfill(char **map, int x, int z,t_data *data);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little);

#endif