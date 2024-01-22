#include <mlx.h>
#include <stdio.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*map_img;
	void	*player;
    int 	x;
    int 	y;
}				t_data;

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,}
};

void draw_map(t_data *img)
{
    int x = 0;
    int y = 0;
    int posw = 0;
    int posh = 0;
	while(y < MAP_HEIGHT)
	{
		while(x < MAP_WIDTH)
		{
			if (map[y][x] == 1)
				mlx_put_image_to_window(img->mlx, img->win, img->map_img, posw, posh);
			x++;
			posw += 45;
		}
		posw = 0;
		y++;
		x = 0;
		posh += 45;
	}
}
void draw_player(t_data *img)
{
    mlx_put_image_to_window(img->mlx, img->win, img->player, img->x, img->y);
}

int key_hook(int keycode, t_data *data)
{

    // if (keycode == 53) // ESC key
    //     exit(0);
	printf("key : %d\n", keycode);
    if (keycode == 123) // Left arrow
        data->x -= 10;
    else if (keycode == 124) // Right arrow
        data->x += 10;
    else if (keycode == 125) // Down arrow
        data->y += 10;
    else if (keycode == 126) // Up arrow
        data->y -= 10;

	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    draw_map(data);
    draw_player(data);
    return 0;
}


int	main(void)
{
	int width = 45;
	int height = 45;
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 45 * MAP_WIDTH, 45 * MAP_HEIGHT, "Hello world!");
	img.img = mlx_xpm_file_to_image(img.mlx, "/Users/ytarhoua/Desktop/so_long0/sky.xpm", &width, &height);
	img.map_img = mlx_xpm_file_to_image(img.mlx, "/Users/ytarhoua/Desktop/so_long0/cloud.xpm", &width, &height);
	img.player = mlx_xpm_file_to_image(img.mlx, "/Users/ytarhoua/Desktop/so_long0/joy.xpm", &width, &height);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	img.x = 0;
    img.y = 0;

	draw_map(&img);
    draw_player(&img);

	mlx_key_hook(img.win, key_hook, &img);
	mlx_loop(img.mlx);
}
