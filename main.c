/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:26 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:27 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	main_init_part(t_cub *cub, t_player *player, t_data *data)
{
	init_data(data);
	init_cub(cub);
	init_pl(player);
	cub->player = *player;
	cub->move_up = 0;
	cub->move_down = 0;
	cub->move_left = 0;
	cub->move_right = 0;
}

void	main_checking_part(t_cub *cub, char **v)
{
	int	i;

	i = 0;
	cub->map = read_map(v[1], cub);
	while (cub->map[i])
		i++;
	cub->map_height = i;
	map_checking(cub->map);
	cub->c_rgb = check_rgb(cub->c);
	cub->f_rgb = check_rgb(cub->f);
}

int	main(int c, char **v)
{
	t_cub		cub;
	t_player	player;
	t_data		data;

	main_init_part(&cub, &player, &data);
	arg_check(v[1], c);
	main_checking_part(&cub, v);
	cub.mlx = mlx_init();
	cub.window = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "CUb3D");
	texture_init(&cub);
	cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
	cub.addr = mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length,
			&cub.endian);
	init_player(&cub);
	mlx_hook(cub.window, 17, 0, (void *)exit, &cub);
	mlx_hook(cub.window, 2, 1L << 0, &move, &cub);
	mlx_hook(cub.window, 3, 1L << 1, &move_release, &cub);
	mlx_loop_hook(cub.mlx, rendring_minimap, &cub);
	mlx_loop(cub.mlx);
}
