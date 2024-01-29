#include "so_long.h"

void set_background(t_data *data)
{
	int x = 0;
	int y = 0;
	int posw = 0;
    int posh = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] != '1')
				mlx_put_image_to_window(data->mlx, data->win, data->background, posw, posh);
			y++;
			posw += 45;
		}
		x++;
		posw = 0;
		posh += 45;
	}
}

void draw_map(t_data *data)
{
    int x = 0;
    int z = 0;
    int posw = 0;
    int posh = 0;
	while(data->map[x])
	{
		z = 0;
		while(data->map[x][z])
		{
			if (data->map[x][z] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->map_data, posw, posh);
			z++;
			posw += 45;
		}
		posw = 0;
		x++;
		posh += 45;
	}
}

void draw_coins(t_data *data)
{
    int x = 0;
    int z = 0;
    int posw = 0;
    int posh = 0;
	while(data->map[x])
	{
		z = 0;
		while(data->map[x][z])
		{
			if (data->map[x][z] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->bone, posw, posh);
			else if (data->map[x][z] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->hole, posw, posh);
			z++;
			posw += 45;
		}
		posw = 0;
		x++;
		posh += 45;
	}
}
void draw_player(t_data *data)
{
	if (data->position == 'u')
    	mlx_put_image_to_window(data->mlx, data->win, data->u_player, data->posx, data->posy);
	if (data->position == 'd')
    	mlx_put_image_to_window(data->mlx, data->win, data->pic_player, data->posx, data->posy);
	if (data->position == 'l')
    	mlx_put_image_to_window(data->mlx, data->win, data->r_player, data->posx, data->posy);
	if (data->position == 'r')
    	mlx_put_image_to_window(data->mlx, data->win, data->l_player, data->posx, data->posy);
}

void check_stop(int key, int c, t_data *data, int i)
{
	// printf("posx is %i and posy is %i\n", data->playerx, data->playery);
	if (c == 'E')
	{
		if (data->coins == data->check_coins &&(
		 (data->map[data->playery - 1][data->playerx] == c && key == 126)
		|| (data->map[data->playery + 1][data->playerx]  == c && key == 125)
		|| (data->map[data->playery][data->playerx + 1]  == c && key == 124)
		|| (data->map[data->playery][data->playerx - 1]  == c && key == 123)))
		{
			ft_error("YOU WIN!\n");
		}
	}
	if ((data->map[data->playery - 1][data->playerx] == c && key == 126)
		|| (data->map[data->playery + 1][data->playerx]  == c && key == 125)
		|| (data->map[data->playery][data->playerx + 1]  == c && key == 124)
		|| (data->map[data->playery][data->playerx - 1]  == c && key == 123))
	{
		data->move = 0;
		data->check_count = 0;
	}
	if (data->map[data->playery][data->playerx] == 'C' && i == 1)
	{
		data->map[data->playery][data->playerx] = '0';
		data->check_coins += 1;
		printf("check coins is %i\n", data->check_coins);
	}
}
void move(int key, t_data *data)
{
	// printf("key : %d\n", key);
	// printf("counter is : %i\n", data->check_count);
	// printf("pos player x: %i and y; %i, move = %d\n", data->playerx, data->playery, data->move);
    if (data->check_count != 0 && key == 126)
	{
        data->posy -= data->move;
		data->position = 'u';
	} // up arrow
    else if (data->check_count != 0 && key == 125)
	{
        data->posy += data->move;
		data->position = 'd';
	} // down arrow
    else if (data->check_count != 0 && key == 124)
	{
		data->posx += data->move;
		data->position = 'r';
	} // right arrow 
    else if (data->check_count != 0 && key == 123)
	{
		data->posx -= data->move;
		data->position = 'l';
	} // left arrow
}

int key_hook(int keys,t_data *data)
{
	data->playerx = data->posx / 45;
	data->playery = data->posy / 45;
	data->check_count = 1;
	data->move = 45;
	check_stop(keys, 'E',data, 1);
	check_stop(keys, '1',data, 0);
	if (data->check_count == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->background, data->posx, data->posy);
	move(keys, data);
	draw_player(data);
    if (keys == 53) // ESC key
         exit(0);
	return (0);
}

// int	main(void)
// {
// 	int width = 45;
// 	int height = 45;
// 	t_info	data;

// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, 45 * MAP_WIDTH, 45 * MAP_HEIGHT, "Hello world!");
// 	data.data = mlx_xpm_file_to_image(data.mlx, "/Users/ytarhoua/Desktop/so_long0/sky.xpm", &width, &height);
// 	data.map_data = mlx_xpm_file_to_image(data.mlx, "/Users/ytarhoua/Desktop/so_long0/cloud.xpm", &width, &height);
// 	data.player = mlx_xpm_file_to_image(data.mlx, "/Users/ytarhoua/Desktop/so_long0/joy.xpm", &width, &height);
// 	mlx_put_image_to_window(data.mlx, data.win, data.data, 0, 0);

// 	data.x = 0;
//     data.y = 0;

// 	draw_map(&data);
//     draw_player(&data);

// 	mlx_key_hook(data.win, key_hook, &data);
// 	mlx_loop(data.mlx);
// }

void images(t_data *data)
{
	data->background = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/herb.xpm", &data->img_size, &data->img_size);
	data->map_data = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/wall.xpm", &data->img_size, &data->img_size);
	data->pic_player = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/front_zombie.xpm", &data->img_size, &data->img_size);
	data->l_player = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/zombie_left.xpm", &data->img_size, &data->img_size);
	data->r_player = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/zombie_right.xpm", &data->img_size, &data->img_size);
	data->u_player = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/back_zombie.xpm", &data->img_size, &data->img_size);
	data->bone = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/bone.xpm", &data->img_size, &data->img_size);
	data->hole = mlx_xpm_file_to_image(data->mlx, "/Users/ytarhoua/Desktop/so_long0/hole.xpm", &data->img_size, &data->img_size);

}

int main(int argc, char** argv)
{
	t_data data;
	data.img_size = 45;
	data.check_coins = 0;

	if (argc < 2 || !ft_strnstr(argv[1], ".ber"))
		ft_error("few arges\n");

	data.fd = open(argv[1], O_RDWR);
	if (data.fd < 0)
		ft_error("error\n");
	check_map(&data);
	new_line(&data);
	check_char(&data);
	check_wall(&data);
	floodfill_check(&data);
	// printf("%i\n", data.width);
	// printf("%i\n", data.lines);
	data.lines += 1;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (45 * data.width), (45 * data.lines), "Hello world!");
	data.posy = data.playery * 45;
	data.posx = data.playerx * 45;
	data.position = 'd';
	//printf("coins is : %i\n", data.coins);
	images(&data);
	mlx_hook(data.win,2,0, key_hook, &data);
	set_background(&data);

	draw_map(&data);
	draw_coins(&data);
	draw_player(&data);

	mlx_loop(data.mlx);
}