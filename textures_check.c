#include "cub3d.h"

int	check_NO(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
	{
		if (v[i] == 'N' && v[i + 1] == 'O' && v[i + 2] == ' ')
			return (i + 3);
	}
	return (0);
}
int	check_SO(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
		if (v[i] == 'S' && v[i + 1] == 'O' && v[i + 2] == ' ')
			return (i + 3);
	return (0);
}
int	check_WE(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
		if (v[i] == 'W' && v[i + 1] == 'E' && v[i + 2] == ' ')
			return (i + 3);
	return (0);
}
int	check_EA(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
		if (v[i] == 'E' && v[i + 1] == 'A' && v[i + 2] == ' ')
			return (i + 3);
	return (0);
}
int	check_F(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	if (v[i] != ' ' && v[i] != '	')
		if (v[i] == 'F' && v[i + 1] == ' ')
			return (i + 2);
	return (0);
}
int	check_C(char *v)
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

// void	textures_error(char *path)
// {
// 	ft_putstr_fd("error: texture '", 2);
// 	ft_putstr_fd(path, 2);
// 	ft_putstr_fd("' not found.\n", 2);
// 	exit(0);
// }

// void	take_img_adr(t_image *t)
// {
// 	t->addr = mlx_get_data_addr(t->img, &(t->bits_per_pixel), &(t->line_length),
// 			&(t->endian));
// }

// void	resit_xy(int *x, int *y)
// {
// 	(*x) = 0;
// 	(*y) = 0;
// }
// void	texture_init(t_cub *game)
// {
// 	game->t[0].img = mlx_xpm_file_to_image(game->mlx, game->no, &(game->t[0].w),
// 			&(game->t[0].h));
// 	if (!game->t[0].img)
// 		textures_error(game->no);
// 	take_img_adr(&game->t[0]);
// 	game->t[0].x = 0;
// 	game->t[0].y = 0;
// 	game->t[1].img = mlx_xpm_file_to_image(game->mlx, game->so, &(game->t[1].w),
// 			&(game->t[1].h));
// 	if (!game->t[1].img)
// 		textures_error(game->so);
// 	take_img_adr(&game->t[1]);
// 	game->t[1].x = 0;
// 	game->t[1].y = 0;
// 	game->t[2].img = mlx_xpm_file_to_image(game->mlx, game->we, &(game->t[2].w),
// 			&(game->t[2].h));
// 	if (!game->t[2].img)
// 		textures_error(game->we);
// 	take_img_adr(&game->t[2]);
// 	game->t[2].x = 0;
// 	game->t[2].y = 0;
// 	game->t[3].img = mlx_xpm_file_to_image(game->mlx, game->ea, &(game->t[3].w),
// 			&(game->t[3].h));
// 	if (!game->t[3].img)
// 		textures_error(game->ea);
// 	take_img_adr(&game->t[3]);
// 	game->t[3].x = 0;
// 	game->t[3].y = 0;
// }