/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:38 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:39 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pl(t_player *pl)
{
	pl->x = 0;
	pl->y = 0;
}

void	init_cub(t_cub *cub)
{
	cub->map = NULL;
	cub->c = NULL;
	cub->f = NULL;
	cub->ea = NULL;
	cub->we = NULL;
	cub->so = NULL;
	cub->no = NULL;
	cub->count = 0;
	cub->mlx = NULL;
	cub->window = NULL;
	cub->height = 0;
	cub->width = 0;
	cub->x = 0;
	cub->y = 0;
	cub->pos_x = 0;
	cub->pos_y = 0;
	cub->img = NULL;
	cub->f_rgb = 0;
	cub->c_rgb = 0;
	cub->addr = NULL;
	cub->bits_per_pixel = 0;
	cub->line_length = 0;
	cub->endian = 0;
	cub->orientation = 0;
}

void	init_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
}

void	init_rays(t_rays *r)
{
	r->x = 0;
	r->y = 0;
	r->counter = 0;
	r->orientation = 0;
	r->xx = 0;
	r->yy = 0;
	r->hit_vert = 0;
	r->hit_horz = 0;
	r->increment = 0;
}

void	init_tpars1(t_pars1 *p)
{
	p->i = 0;
	p->j = 0;
	p->count = 0;
	p->count2 = 0;
	p->k = 0;
}
