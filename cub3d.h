/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:11 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/24 16:48:06 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define WIDTH 1080
# define HEIGHT 1080
# define SIZE 64
# define PI 3.14
# define ANGLE 30
# define EAST 0
# define WEST 1
# define NORTH 2
# define SOUTH 3

typedef struct s_pars1
{
	size_t		i;
	size_t		j;
	int			count;
	size_t		count2;
	int			k;
}				t_pars1;

typedef struct s_pars2
{
	int			color;
	int			y;
	double		j;
	double		l;
	int			text_ort;
}				t_pars2;

typedef struct s_rays
{
	double		x;
	double		y;
	int			counter;
	double		orientation;
	double		xx;
	double		yy;
	int			hit_vert;
	int			hit_horz;
	double		increment;
}				t_rays;

typedef struct s_player
{
	float		x;
	float		y;

}				t_player;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	double		x;
	double		y;
}				t_image;
typedef struct s_cub
{
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	int			count;
	void		*mlx;
	void		*window;
	void		*img;
	int			height;
	int			width;
	int			x;
	int			y;
	int			pos_x;
	int			pos_y;
	int			f_rgb;
	int			c_rgb;
	int			x_wall;
	int			y_wall;
	t_player	player;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_data		data;
	float		orientation;
	double		hight_wall;
	int			bottom;
	int			top;
	int			or_t;
	int			map_height;
	t_image		t[4];
	bool		move_up;
	bool		move_down;
	bool		move_right;
	bool		move_left;
	bool		turn_right;
	bool		turn_left;
}				t_cub;

char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			**read_map(char *map, t_cub *cub);
void			arg_check(char *v, int c);
size_t			ft_strlen(char *c);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_reste(char *s);
char			*ft_get_line(char *s);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_substr(char *s, int start, int len);
char			**join_all(char *s, char c);
void			check_textures_path(t_cub *cub);
int				ft_atoi(char *str);
void			error_msg(char *msg);
void			map_checking(char **map);
int				check_we(char *s);
int				check_no(char *s);
int				check_so(char *s);
int				check_ea(char *s);
int				check_f(char *s);
int				check_c(char *s);
int				skip_space(char *s);
void			check_path(char *s);
int				check_empty_space(char *s);
void			empty_file(char *s);
void			ft_putstr_fd(char *s, int fd);
int				rendring_minimap(t_cub *cub);
void			draw_wall(t_cub *cub, int x, int y);
void			draw_colone(t_cub *cub, int x, int y);
void			draw_line(t_cub *cub, int x, int y);
void			my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void			ft_free(char **str);
void			init_tpars1(t_pars1 *p);
void			init_pl(t_player *pl);
void			init_cub(t_cub *cub);
void			init_data(t_data *data);
void			init_rays(t_rays *r);
char			**check_rgb_number(int i, char *rgb);
void			check_rgb_character(char *n, int i);
int				check_rgb(char *rgb);
void			check_nb_rgb(char *s);
void			check_first_line(char *s);
void			check_around_zero(char **map, int i, int j);
void			empty_file(char *v);
void			empty_line(char v);
double			make_it_good(t_cub *game, double orientation,
					double o_distance);
void			make_wall(t_cub *cub, double orientation);
void			dr_wall(t_cub *cub, int counter, int hit_vert, int hit_horz);
void			rays(t_cub *pos);
void			take_text_or(double orientation, t_cub *pos, int hit_vert,
					int hit_horz);
void			update_xy(t_rays *r);
void			draw_3d(t_cub *pos, t_rays *r);
double			calcul_distance(t_cub *cub);
void			textures_error(char *path);
void			texture_init(t_cub *cub);
int				get_texture_color(t_cub *cub, int x, int y, int text_ort);
void			resit_xy(double *x, double *y);
void			take_img_adr(t_image *t);
int				or_text(int or);
int				make_color(int y, int color, int counter, t_cub *cub);
int				take_rgbcolor(int color, t_cub *cub, int y);
void			init_pars2(t_pars2 *p);
void			draw_empty(t_cub *cub, int x, int y);
void			draw_player_position(t_cub *cub);
void			draw(t_cub *cub, int i, int j);
void			draw2(t_cub *cub, int i, int j);
void			draw_map(t_cub *cub);
void			calculatenewposition(t_cub *cub, float ort, float dist);
int				move(int keycode, t_cub *cub);
void			fill_orientation(char c, t_cub *cub);
void			init_player(t_cub *cub);
char			*take_paths(char *path, char *v, int *count, int i);
int				check_tex1(int i, char *v, t_cub *cub);
int				check_tex2(int i, char *v, t_cub *cub);
void			fill_textures(t_cub *cub, char *v);
void			file_existance(int fd, char *s);
int				move_release(int keycode, t_cub *cub);
int				player_check(char c);
#endif
