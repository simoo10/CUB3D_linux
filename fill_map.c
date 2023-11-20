#include "cub3d.h"

char	*take_paths(char *path, char *v, int *count, int i)
{
	char	*s;

	if (path)
		error_msg("Oops!Something Happens!\n");
	s = ft_substr(v, i, ft_strlen(v) - (i + 1));
	(*count)++;
	return (s);
}

int	check_tex1(int i, char *v, t_cub *cub)
{
	if (check_NO(v))
	{
		i = check_NO(v);
		cub->no = take_paths(cub->no, v, &cub->count, i);
		return (0);
	}
	else if (check_SO(v))
	{
		i = check_SO(v);
		cub->so = take_paths(cub->so, v, &cub->count, i);
		return (0);
	}
	else if (check_EA(v))
	{
		i = check_EA(v);
		cub->ea = take_paths(cub->ea, v, &cub->count, i);
		return (0);
	}
	return (1);
}
int	check_tex2(int i, char *v, t_cub *cub)
{
	if (check_tex1(i, v, cub) == 0)
	{
		return (0);
	}
	else if (check_WE(v))
	{
		i = check_WE(v);
		cub->we = take_paths(cub->we, v, &cub->count, i);
		return (0);
	}
	else if (check_C(v))
	{
		i = check_C(v);
		cub->c = take_paths(cub->c, v, &cub->count, i);
		return (0);
	}
	else if (check_F(v))
	{
		i = check_F(v);
		cub->f = take_paths(cub->f, v, &cub->count, i);
		return (0);
	}
	return (1);
}

void	fill_textures(t_cub *cub, char *v)
{
	int	i;

	i = 0;
	if (check_tex2(i, v, cub) == 0)
		return ;
	else
		error_msg("Oops!Something Happens!\n");
}
void	file_existance(int fd, char *s)
{
	if (fd == -1)
	{
		printf("s = %s\n", s);
		free(s);
		close(fd);
		error_msg("Oops!This Path Not Found!\n");
	}
}

char	*check_empty_lines(char *line, int fd)
{
	while (line)
	{
		if (check_empty_space(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		break ;
	}
	return (line);
}

char	*fill_all_map(char *line, int fd)
{
	char	*v;
	int		e;

	e = 0;
	v = NULL;
	line = get_next_line(fd);
	line = check_empty_lines(line, fd);
	while (line)
	{
		e = skip_space(line);
		if (line[e] == '\n')
			error_msg("Oops!Empty Line in Map!\n");
		if (line[e] != '1')
			error_msg("Oops!Map Has An Error!\n");
		v = ft_strjoin(v, line);
		free(line);
		line = get_next_line(fd);
	}
	return (v);
}
char	*take_textures_paths(char *line, t_cub *cub, int fd)
{
	while (line)
	{
		if (check_empty_space(line))
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		fill_textures(cub, line);
		if (cub->count == 6)
			break ;
		line = get_next_line(fd);
	}
	return (line);
}
char	**read_map(char *map, t_cub *cub)
{
	int		fd;
	char	*line;
	char	*v;
	char	**split;
	int		i;

	split = NULL;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	v = NULL;
	i = 0;
	line = take_textures_paths(line, cub, fd);
	v = fill_all_map(line, fd);
	empty_file(v);
	i = ft_strlen(v);
	empty_line(v[i - 1]);
	split = ft_split(v, '\n');
	(free(v), close(fd));
	return (split);
}
