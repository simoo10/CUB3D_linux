/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:33 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:34 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculatenewposition(t_cub *cub, float ort, float dist)
{
	float	x_new;
	float	y_new;

	x_new = cub->player.x + dist * cos(ort);
	y_new = cub->player.y + dist * sin(ort);
	if (cub->map[(int)(y_new / SIZE)][(int)(x_new / SIZE)] == '0')
	{
		cub->player.x = x_new;
		cub->player.y = y_new;
	}
}

int	move(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		cub->turn_left = 1;
	if (keycode == 65363)
		cub->turn_right = 1;
	if (keycode == 119)
		cub->move_up = 1;
	if (keycode == 115)
		cub->move_down = 1;
	if (keycode == 100)
		cub->move_right = 1;
	if (keycode == 97)
		cub->move_left = 1;
	return (0);
}

int	move_release(int keycode, t_cub *cub)
{
	if (keycode == 65361)
		cub->turn_left = 0;
	if (keycode == 65363)
		cub->turn_right = 0;
	if (keycode == 119)
		cub->move_up = 0;
	if (keycode == 115)
		cub->move_down = 0;
	if (keycode == 100)
		cub->move_right = 0;
	if (keycode == 97)
		cub->move_left = 0;
	return (0);
}

void	fill_orientation(char c, t_cub *cub)
{
	if (c == 'N')
		cub->orientation = PI * 1.5;
	else if (c == 'S')
		cub->orientation = PI * 0.5;
	else if (c == 'W')
		cub->orientation = 0;
	else if (c == 'E')
		cub->orientation = PI;
}

void	init_player(t_cub *cub)
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
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player.x = (j * SIZE) + (SIZE / 2);
				cub->player.y = (i * SIZE) + (SIZE / 2);
				fill_orientation(cub->map[i][j], cub);
				cub->map[(int)(cub->player.y) / SIZE][(int)(cub->player.x)
					/ SIZE] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
