/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:22:34 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/01/30 18:11:31 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.img_size = 45;
	data.check_coins = 0;
	data.player = 0;
	data.coins = 0;
	data.exit = 0;
	if (argc < 2 || !ft_strnstr(argv[1], ".ber"))
		ft_error("few arges\n", &data);
	data.fd = open(argv[1], O_RDWR);
	if (data.fd < 0)
		ft_error("error\n", &data);
	check_map(&data);
	new_line(&data);
	check_char(&data, 0, 0);
	chars(&data, 0, 0);
	check_wall(&data);
	floodfill_check(&data);
	data.lines += 1;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (45 * data.width),
			(45 * data.lines), "Hello world!");
	data.posy = data.playery * 45;
	data.posx = data.playerx * 45;
	data.position = 'd';
	images(&data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	set_background(&data);
	draw_all(&data, data.map_data, '1');
	draw_all(&data, data.bone, 'C');
	draw_all(&data, data.hole, 'E');
	//draw_map(&data);
	// draw_coins(&data);
	draw_player(&data);
	mlx_loop(data.mlx);
}
