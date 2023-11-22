/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_casting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:45:55 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:47:55 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_text_or(double orientation, t_cub *pos, int hit_vert, int hit_horz)
{
	if (cos(orientation) > 0 && hit_horz)
		pos->or_t = EAST;
	else if (cos(orientation) < 0 && hit_horz)
		pos->or_t = WEST;
	else if (sin(orientation) > 0 && hit_vert)
		pos->or_t = NORTH;
	else if (sin(orientation) < 0 && hit_vert)
		pos->or_t = SOUTH;
}

void	update_xy(t_rays *r)
{
	r->yy = r->y;
	r->xx = r->x;
	r->x += cos(r->orientation);
	r->y += sin(r->orientation);
	r->hit_vert = 0;
	r->hit_horz = 0;
}

void	draw_3d(t_cub *pos, t_rays *r)
{
	pos->x_wall = r->x;
	pos->y_wall = r->y;
	make_wall(pos, r->orientation);
	take_text_or(r->orientation, pos, r->hit_vert, r->hit_horz);
	dr_wall(pos, r->counter, r->hit_vert, r->hit_horz);
	r->counter++;
	r->orientation = r->orientation + r->increment;
}

double	calcul_distance(t_cub *cub)
{
	double	distance;

	distance = sqrt(((cub->player.x - cub->x_wall) * (cub->player.x
					- cub->x_wall)) + ((cub->player.y - cub->y_wall)
				* (cub->player.y - cub->y_wall)));
	return (distance);
}

double	make_it_good(t_cub *game, double orientation, double o_distance)
{
	double	distance;
	double	angledifference;

	angledifference = fabs(game->orientation - orientation);
	if (angledifference < PI / 2)
		distance = o_distance * cos(angledifference);
	else
		distance = o_distance * cos(M_PI - angledifference);
	return (distance);
}
