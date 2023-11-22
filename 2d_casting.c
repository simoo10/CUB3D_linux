/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:45:50 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:45:53 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_empty(t_cub *cub, int x, int y)
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
			my_mlx_pixel_put(cub, (x * SIZE) + i, j + (y * SIZE), 0x007DA8);
			j++;
		}
		i++;
	}
}

void	draw_player_position(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(cub, cub->player.x + i, j + cub->player.y,
					0XFBFF00);
			j++;
		}
		i++;
	}
}

void	draw(t_cub *cub, int i, int j)
{
	draw_wall(cub, j, i);
	draw_colone(cub, j, i);
	draw_line(cub, j, i);
}

void	draw2(t_cub *cub, int i, int j)
{
	draw_empty(cub, j, i);
	draw_colone(cub, j, i);
	draw_line(cub, j, i);
}

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				draw(cub, i, j);
			if (cub->map[i][j] == '0')
				draw2(cub, i, j);
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
				draw2(cub, i, j);
			j++;
		}
		i++;
	}
}
