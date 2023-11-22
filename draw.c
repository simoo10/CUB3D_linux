/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:15 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:16 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_orientation(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 40)
	{
		j = 0;
		while (j < 2)
		{
			my_mlx_pixel_put(cub, (x * SIZE) + i, j + (y * SIZE), 0x00000);
			j++;
		}
		i++;
	}
}

void	draw_wall(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 40)
	{
		j = 0;
		while (j < 40)
		{
			my_mlx_pixel_put(cub, (x * SIZE) + i, j + (y * SIZE), 0xFC3939);
			j++;
		}
		i++;
	}
}

void	draw_colone(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 40)
		{
			my_mlx_pixel_put(cub, (x * SIZE) + i, j + (y * SIZE), 0X0000);
			j++;
		}
		i++;
	}
}

void	draw_line(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 40)
	{
		j = 0;
		while (j < 2)
		{
			my_mlx_pixel_put(cub, (x * SIZE) + i, j + (y * SIZE), 0X0000);
			j++;
		}
		i++;
	}
}
