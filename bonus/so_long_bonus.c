/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytarhoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:22:34 by ytarhoua          #+#    #+#             */
/*   Updated: 2024/02/21 11:27:41 by ytarhoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || check_path(argv[1]) == 1)
		ft_error_one("invalid path");
	ft_checks(&data, argv[1]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (45 * data.width),
			(45 * data.lines), "so_long");
	images(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_exit, &data);
	drawing(&data);
	mlx_loop(data.mlx);
}
