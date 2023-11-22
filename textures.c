/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:43 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:45 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textures_error(char *path)
{
	ft_putstr_fd("error: texture '", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("' not found.\n", 2);
	exit(0);
}

void	take_img_adr(t_image *t)
{
	t->addr = mlx_get_data_addr(t->img, &(t->bits_per_pixel), &(t->line_length),
			&(t->endian));
}

void	resit_xy(double *x, double *y)
{
	(*x) = 0;
	(*y) = 0;
}

void	texture_init(t_cub *game)
{
	game->t[0].img = mlx_xpm_file_to_image(game->mlx, game->no, &(game->t[0].w),
			&(game->t[0].h));
	if (!game->t[0].img)
		textures_error(game->no);
	take_img_adr(&game->t[0]);
	resit_xy(&game->t[0].x, &game->t[0].y);
	game->t[1].img = mlx_xpm_file_to_image(game->mlx, game->so, &(game->t[1].w),
			&(game->t[1].h));
	if (!game->t[1].img)
		textures_error(game->so);
	take_img_adr(&game->t[1]);
	resit_xy(&game->t[1].x, &game->t[1].y);
	game->t[2].img = mlx_xpm_file_to_image(game->mlx, game->we, &(game->t[2].w),
			&(game->t[2].h));
	if (!game->t[2].img)
		textures_error(game->we);
	take_img_adr(&game->t[2]);
	resit_xy(&game->t[2].x, &game->t[2].y);
	game->t[3].img = mlx_xpm_file_to_image(game->mlx, game->ea, &(game->t[3].w),
			&(game->t[3].h));
	if (!game->t[3].img)
		textures_error(game->ea);
	take_img_adr(&game->t[3]);
	resit_xy(&game->t[3].x, &game->t[3].y);
}

int	get_texture_color(t_cub *texture, int x, int y, int text_ort)
{
	int				pixel_position;
	unsigned int	color;

	if (x < 0 || y < 0 || x >= texture->t[text_ort].w
		|| y >= texture->t[text_ort].h)
		return (0);
	pixel_position = y * texture->t[text_ort].line_length + x
		* (texture->t[text_ort].bits_per_pixel / 8);
	color = *(unsigned int *)(texture->t[text_ort].addr + pixel_position);
	return (color);
}
