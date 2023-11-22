/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_casting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:45:58 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:47:51 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_wall(t_cub *cub, double orientation)
{
	double	distance_wall;

	distance_wall = calcul_distance(cub);
	distance_wall = make_it_good(cub, orientation, distance_wall);
	cub->hight_wall = (64 * WIDTH) / distance_wall;
	cub->top = (HEIGHT / 2) - (cub->hight_wall / 2);
	cub->bottom = cub->top + cub->hight_wall;
}

void	dr_wall(t_cub *cub, int counter, int hit_vert, int hit_horz)
{
	t_pars2	p;

	init_pars2(&p);
	p.text_ort = or_text(cub->or_t);
	if (hit_vert)
		cub->t[p.text_ort].x = (int)cub->x_wall % (int)cub->t[p.text_ort].w;
	else if (hit_horz)
		cub->t[p.text_ort].x = (int)cub->y_wall % (int)cub->t[p.text_ort].w;
	cub->t[p.text_ort].y = 0;
	p.j = (double)cub->t[p.text_ort].h / cub->hight_wall;
	while (p.y < HEIGHT && p.text_ort < 4)
	{
		p.color = take_rgbcolor(p.color, cub, p.y);
		if (p.color == -5)
		{
			p.l = cub->t[p.text_ort].y;
			if (cub->hight_wall > HEIGHT)
				cub->t[p.text_ort].y += p.j * (cub->hight_wall - HEIGHT) / 2;
			p.color = get_texture_color(cub, cub->t[p.text_ort].x,
					cub->t[p.text_ort].y, p.text_ort);
			cub->t[p.text_ort].y = p.l;
			cub->t[p.text_ort].y += p.j;
		}
		p.y = make_color(p.y, p.color, counter, cub);
	}
}

void	rays(t_cub *pos)
{
	t_rays	r;

	init_rays(&r);
	r.orientation = pos->orientation - (PI / 6);
	r.increment = (PI / 3) / WIDTH;
	while (r.orientation < pos->orientation + (PI / 6))
	{
		r.x = pos->player.x;
		r.y = pos->player.y;
		while (1)
		{
			update_xy(&r);
			if (pos->map[(int)r.y / SIZE][(int)(r.xx) / SIZE] == '1')
				r.hit_vert = 1;
			if (pos->map[(int)(r.yy) / SIZE][(int)r.x / SIZE] == '1')
				r.hit_horz = 1;
			if (r.y / SIZE <= 0 || r.x / SIZE <= 0 || r.y
				/ SIZE >= pos->map_height || r.x
				/ SIZE >= ft_strlen(pos->map[(int)(r.y / SIZE)])
				|| pos->map[(int)(r.y / SIZE)][(int)(r.x / SIZE)] == '1')
				break ;
		}
		draw_3d(pos, &r);
	}
}

int	move_player(t_cub *cub)
{
	if (cub->turn_left)
		cub->orientation -= (PI / 180) * 2;
	if (cub->turn_right)
		cub->orientation += (PI / 180) * 2;
	if (cub->move_up)
		calculatenewposition(cub, cub->orientation, 4);
	if (cub->move_down)
		calculatenewposition(cub, cub->orientation, -4);
	if (cub->move_right)
		calculatenewposition(cub, cub->orientation + (PI * 0.5), 4);
	if (cub->move_left)
		calculatenewposition(cub, cub->orientation - (PI * 0.5), 4);
	return (0);
}

int	rendring_minimap(t_cub *cub)
{
	move_player(cub);
	mlx_clear_window(cub->mlx, cub->window);
	draw_player_position(cub);
	rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	return (0);
}
