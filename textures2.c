/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:46 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:49 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	or_text(int or)
{
	int	text_ort;

	text_ort = 0;
	if (or == EAST)
		text_ort = EAST;
	else if (or == WEST)
		text_ort = WEST;
	else if (or == NORTH)
		text_ort = NORTH;
	else if (or == SOUTH)
		text_ort = SOUTH;
	return (text_ort);
}

int	take_rgbcolor(int color, t_cub *cub, int y)
{
	if (y < cub->top)
		color = cub->c_rgb;
	else if (y > cub->bottom)
		color = cub->f_rgb;
	else
		color = -5;
	return (color);
}

int	make_color(int y, int color, int counter, t_cub *cub)
{
	my_mlx_pixel_put(cub, counter, y, color);
	y++;
	return (y);
}

void	init_pars2(t_pars2 *p)
{
	p->color = 0;
	p->y = 0;
	p->j = 0;
	p->l = 0;
	p->text_ort = 0;
}

int	check_c(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
		if (v[i] == 'C' && v[i + 1] == ' ')
			return (i + 2);
	return (0);
}
