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

double	make_it_good(t_cub *game, double orientation, double o_distance)
{
	double	distance;
	double	angleDifference;

	angleDifference = fabs(game->orientation - orientation);
	if (angleDifference < PI / 2)
		distance = o_distance * cos(angleDifference);
	else
		distance = o_distance * cos(M_PI - angleDifference);
	return (distance);
}

void	make_wall(t_cub *cub, double orientation)
{
	double	distance_Wall;

	distance_Wall = calcul_distance(cub);
	distance_Wall = make_it_good(cub, orientation, distance_Wall);
	cub->hight_Wall = (64 * WIDTH) / distance_Wall;
	cub->top = (HEIGHT / 2) - (cub->hight_Wall / 2);
	cub->bottom = cub->top + cub->hight_Wall;
}

int	get_texture_color(t_cub *texture, int x, int y, int text_ort)
{
	int				pixel_position;
	unsigned int	color;

	// printf("-----=====%d",text_ort);
	if (x < 0 || y < 0 || x >= texture->t[text_ort].w
		|| y >= texture->t[text_ort].h)
		return (0);
	pixel_position = y * texture->t[text_ort].line_length + x
		* (texture->t[text_ort].bits_per_pixel / 8);
	color = *(unsigned int *)(texture->t[text_ort].addr + pixel_position);
	return (color);
}
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
void	dr_wall(t_cub *cub, int counter, int hit_vert, int hit_horz)
{
	int		color;
	int		y;
	double	j;
	double	l;
	int		text_ort;

	text_ort = or_text(cub->or);
	y = 0;
	if (hit_vert)
		cub->t[text_ort].x = (int)cub->x_wall % (int)cub->t[text_ort].w;
	else if (hit_horz)
		cub->t[text_ort].x = (int)cub->y_wall % (int)cub->t[text_ort].w;
	cub->t[text_ort].y = 0;
	j = (double)cub->t[text_ort].h / cub->hight_Wall;
	while (y < HEIGHT && text_ort < 4)
	{
		if (y < cub->top)
			color = cub->f_rgb;
		else if (y > cub->bottom)
			color = cub->c_rgb;
		else
		{
			l = cub->t[text_ort].y;
			if (cub->hight_Wall > HEIGHT)
				cub->t[text_ort].y += j * (cub->hight_Wall - HEIGHT) / 2;
			color = get_texture_color(cub, cub->t[text_ort].x,
					cub->t[text_ort].y, text_ort);
			cub->t[text_ort].y = l;
			cub->t[text_ort].y += j;
		}
		my_mlx_pixel_put(cub, counter, y, color);
		y++;
	}
}
void	take_text_or(double orientation, t_cub *pos, int hit_vert, int hit_horz)
{
	if (cos(orientation) > 0 && hit_horz)
		pos->or = EAST;
	else if (cos(orientation) < 0 && hit_horz)
		pos->or = WEST;
	else if (sin(orientation) > 0 && hit_vert)
		pos->or = NORTH;
	else if (sin(orientation) < 0 && hit_vert)
		pos->or = SOUTH;
}
void	rays(t_cub *pos)
{
	double	x;
	double	y;
	int		counter;
	double	orientation;
	double	xx;
	double	yy;
	int		hit_vert;
	int		hit_horz;
	double	increment;

	counter = 0;
	orientation = pos->orientation - (PI / 6);
	increment = (PI / 3) / WIDTH;
	while (orientation < pos->orientation + (PI / 6))
	{
		x = pos->player.x;
		y = pos->player.y;
		while (1)
		{
			yy = y;
			xx = x;
			x += cos(orientation);
			y += sin(orientation);
			hit_vert = 0;
			hit_horz = 0;
			if (pos->map[(int)y / SIZE][(int)(xx) / SIZE] == '1')
				hit_vert = 1;
			if (pos->map[(int)(yy) / SIZE][(int)x / SIZE] == '1')
				hit_horz = 1;
			if (y / SIZE <= 0 || x / SIZE <= 0 || y / SIZE >= pos->map_height
				|| x / SIZE >= ft_strlen(pos->map[(int)(y / SIZE)])
				|| pos->map[(int)(y / SIZE)][(int)(x / SIZE)] == '1')
				break ;
		}
		pos->x_wall = x;
		pos->y_wall = y;
		make_wall(pos, orientation);
		take_text_or(orientation, pos, hit_vert, hit_horz);
		dr_wall(pos, counter, hit_vert, hit_horz);
		counter++;
		orientation = orientation + increment;
	}
}

double	calcul_distance(t_cub *cub)
{
	double	distance;

	distance = sqrt(((cub->player.x - cub->x_wall) * (cub->player.x
					- cub->x_wall)) + ((cub->player.y - cub->y_wall)
				* (cub->player.y - cub->y_wall)));
	return (distance);
}

void	init_data(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
}
int	rendring_minimap(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->window);
	//draw_map(cub);
	draw_player_position(cub);
	rays(cub);
	//k=calcul_distance(cub);
	//printf("------->%f\n",k);
	mlx_put_image_to_window(cub->mlx, cub->window, cub->img, 0, 0);
	return (0);
}

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

void	calculateNewPosition(t_cub *cub, float ort, float dist)
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
		cub->orientation -= (PI / 180) * 2;
	if (keycode == 65363)
		cub->orientation += (PI / 180) * 2;
	if (keycode == 119)
		calculateNewPosition(cub, cub->orientation, 4);
	if (keycode == 115)
		calculateNewPosition(cub, cub->orientation, -4);
	if (keycode == 100)
		calculateNewPosition(cub, cub->orientation + (PI * 0.5), 4);
	if (keycode == 97)
		calculateNewPosition(cub, cub->orientation - (PI * 0.5), 4);
	return (0);
}

void	fill_orientation(char c, t_cub *cub)
{
	printf("c = %c\n", c);
	if (c == 'N')
	{
		printf("[[[[]]]]\n");
		cub->orientation = PI * 1.5;
		printf("++orientation = %f\n", cub->orientation);
	}
	else if (c == 'S')
	{
		cub->orientation = PI * 0.5;
		printf("--orientation = %f\n", cub->orientation);
	}
	else if (c == 'W')
	{
		cub->orientation = 0;
		printf("##orientation = %f\n", cub->orientation);
	}
	else if (c == 'E')
	{
		cub->orientation = PI;
		printf("...orientation = %f\n", cub->orientation);
	}
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
				// printf("x = %f\n",cub->player.x);
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
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
int	main(int c, char **v)
{
	t_cub		cub;
	t_player	player;
	t_data		data;
	int			i;

	init_data(&data);
	init_cub(&cub);
	init_pl(&player);
	cub.player = player;
	arg_check(v[1], c);
	cub.map = read_map(v[1], &cub);
	i = 0;
	while (cub.map[i])
		i++;
	cub.map_height = i;
	i = 0;
	//check_textures_path(&cub);
	map_checking(cub.map);
	cub.c_rgb = check_rgb(cub.c);
	cub.f_rgb = check_rgb(cub.f);
	cub.mlx = mlx_init();
	cub.window = mlx_new_window(cub.mlx, WIDTH, HEIGHT, "CUb3D");
	texture_init(&cub);
	cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT);
	cub.addr = mlx_get_data_addr(cub.img, &cub.bits_per_pixel, &cub.line_length,
			&cub.endian);
	init_player(&cub);
	mlx_hook(cub.window, 17, 0, (void *)exit, &cub);
	mlx_hook(cub.window, 2, 1L << 0, &move, &cub);
	mlx_loop_hook(cub.mlx, rendring_minimap, &cub);
	mlx_loop(cub.mlx);
}
