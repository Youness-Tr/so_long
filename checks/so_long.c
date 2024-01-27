#include "so_long.h"

void set_background(t_info *graph, t_data *data)
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
				mlx_put_image_to_window(graph->mlx, graph->win, graph->background, posw, posh);
			y++;
			posw += 45;
		}
		x++;
		posw = 0;
		posh += 45;
	}
}

void draw_map(t_data *data, t_info *graph)
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
				mlx_put_image_to_window(graph->mlx, graph->win, graph->map_graph, posw, posh);
			z++;
			posw += 45;
		}
		posw = 0;
		x++;
		posh += 45;
	}
}
void draw_player(t_info *graph, t_data *data)
{
    mlx_put_image_to_window(graph->mlx, graph->win, graph->player, data->posx, data->posy);
}

int key_hook(int keycode, t_info *graph, t_data *data)
{
	
    // if (keycode == 53) // ESC key
    //     exit(0);
	printf("key : %d\n", keycode);
    if (keycode == 123) // Left arrow
        data->posx -= 45;
    else if (keycode == 124) // Right arrow
        data->posx += 45;
    else if (keycode == 125) // Down arrow
        data->posy += 45;
    else if (keycode == 126) // Up arrow
        data->posy -= 45;

	mlx_clear_window(graph->mlx, graph->win);
	//set_background(graph, data);
	//printf("key : %d\n", keycode);
    //draw_map(data ,graph);
    draw_player(graph, data);
    return 0;
}


// int	main(void)
// {
// 	int width = 45;
// 	int height = 45;
// 	t_info	graph;

// 	graph.mlx = mlx_init();
// 	graph.win = mlx_new_window(graph.mlx, 45 * MAP_WIDTH, 45 * MAP_HEIGHT, "Hello world!");
// 	graph.graph = mlx_xpm_file_to_image(graph.mlx, "/Users/ytarhoua/Desktop/so_long0/sky.xpm", &width, &height);
// 	graph.map_graph = mlx_xpm_file_to_image(graph.mlx, "/Users/ytarhoua/Desktop/so_long0/cloud.xpm", &width, &height);
// 	graph.player = mlx_xpm_file_to_image(graph.mlx, "/Users/ytarhoua/Desktop/so_long0/joy.xpm", &width, &height);
// 	mlx_put_image_to_window(graph.mlx, graph.win, graph.graph, 0, 0);

// 	graph.x = 0;
//     graph.y = 0;

// 	draw_map(&graph);
//     draw_player(&graph);

// 	mlx_key_hook(graph.win, key_hook, &graph);
// 	mlx_loop(graph.mlx);
// }

void images(t_info *graph)
{
	graph->background = mlx_xpm_file_to_image(graph->mlx, "/Users/ytarhoua/Desktop/so_long0/herb.xpm", &graph->img_size, &graph->img_size);
	graph->map_graph = mlx_xpm_file_to_image(graph->mlx, "/Users/ytarhoua/Desktop/so_long0/wall.xpm", &graph->img_size, &graph->img_size);
	graph->player = mlx_xpm_file_to_image(graph->mlx, "/Users/ytarhoua/Desktop/so_long0/front_zombie.xpm", &graph->img_size, &graph->img_size);
}

int main(int argc, char** argv)
{
	t_data data;
	t_info graph;
	graph.img_size = 45;

	if (argc < 2 || !ft_strnstr(argv[1], ".ber"))
	{
		printf("few arges\n");
		exit(1);
	}

	data.fd = open(argv[1], O_RDWR);
	if (data.fd < 0)
	{
		printf("error\n");
		exit(1);
	}
	check_map(&data);
	new_line(&data);
	check_char(&data);
	check_wall(&data);
	floodfill_check(&data);
	// printf("%i\n", data.width);
	// printf("%i\n", data.lines);
	data.lines += 1;

	graph.mlx = mlx_init();
	graph.win = mlx_new_window(graph.mlx, (45 * data.width), (45 * data.lines), "Hello world!");
	images(&graph);
	mlx_key_hook(graph.win, key_hook, &graph);
	set_background(&graph, &data);
	
	draw_map(&data ,&graph);
	draw_player(&graph, &data);
	data.posx *= 45;
	data.posy *= 45;
	
	mlx_loop(graph.mlx);
}