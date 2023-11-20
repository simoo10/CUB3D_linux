#include "cub3d.h"

void	arg_check(char *v, int c)
{
	char	*s;
	int		i;
	int		j;

	s = ".cub";
	i = 0;
	j = 0;
	if (c != 2)
	{
		printf("INVALID NUMBER OF ARGUMENT!\n");
		exit(1);
	}
	i = ft_strlen(v) - 4;
	while (s[j] && v[i])
	{
		if (s[j] != v[i])
			(printf("INVALID MAP NAME\n"), exit(1));
		j++;
		i++;
	}
}

void	empty_file(char *v)
{
	int	i;

	i = 0;
	if (v == NULL)
		(printf("Error\nOops!Empty File!\n"), exit(1));
	while (v[i])
	{
		if (v[i] != ' ' && v[i] != '	' && v[i] != '\n')
			return ;
		i++;
	}
	(printf("Error\nOops!Empty File!\n"), exit(1));
}

void	empty_line(char v)
{
	if (v == '\n')
	{
		printf("Error\n---MAP HAVE EMPTY LINE IN THE LAST LINE---\n");
		exit(1);
	}
}

int	check_empty_space(char *v)
{
	size_t	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	' || v[i] == '\n'))
		i++;
	if (i == ft_strlen(v))
		return (1);
	return (0);
}

int	skip_space(char *v)
{
	int	i;

	i = 0;
	while (v[i] && (v[i] == ' ' || v[i] == '	'))
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		i++;
	}
	write(fd, s, i);
}
char	**check_rgb_number(int i, char *rgb)
{
	int		count;
	char	**n;

	count = 0;
	n = NULL;
	i = skip_space(rgb);
	while (rgb[i])
	{
		if (rgb[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		error_msg("Oops!Invalid RGB!\n");
	i = skip_space(rgb);
	n = ft_split(rgb + i, ',');
	free(rgb);
	while (n[i])
		i++;
	if (i != 3)
		error_msg("Oops!Invalid RGB!\n");
	return (n);
}
void	check_rgb_character(char *n, int i)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if (n[j] < '0' || n[j] > '9')
		{
			if (i == 2 && j == ft_strlen(n) - 1)
			{
				if (n[j] == '\n')
					break ;
			}
			error_msg("Oops!Invalid RGB!\n");
		}
		j++;
	}
	if (j > 3)
		error_msg("##Oops!Invalid RGB!\n");
}
int	check_rgb(char *rgb)
{
	int		i;
	int		color;
	char	**n;

	i = 0;
	n = check_rgb_number(i, rgb);
	while (n[i])
	{
		check_rgb_character(n[i], i);
		i++;
	}
	i = -1;
	while (n[++i])
		check_nb_rgb(n[i]);
	i = 0;
	color = (ft_atoi(n[0]) << 16) | (ft_atoi(n[1]) << 8) | ft_atoi(n[2]);
	return (ft_free(n), color);
}
void	check_nb_rgb(char *s)
{
	int	nb;

	nb = 0;
	nb = ft_atoi(s);
	if (nb < 0 || nb > 255)
		error_msg("---Oops!Invalid RGB!---\n");
}

void	check_around_zero(char **map, int i, int j)
{
	if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ')
	{
		error_msg("====Oops!Map Has An Error!\n");
	}
}
void	check_first_line(char *map)
{
	size_t	i;

	i = skip_space(map);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ')
			error_msg("@@@@Oops!Map Should surrounded by wall!\n");
		i++;
	}
}

void	check_last_line(char *map, int i, int count2)
{
	size_t	j;

	j = 0;
	if (i == count2 - 1)
	{
		j = 0;
		while (map[j])
		{
			if (map[j] != '1' && map[j] != ' ')
				error_msg("==---==Oops!Map Should surrounded by wall!\n");
			j++;
		}
	}
}

int	check_line(char *map, int k, int j, int count)
{
	if (map[k] != '1' || map[ft_strlen(map) - 1] != '1')
		error_msg("------Oops!Map Should surrounded by wall!\n");
	if (map[j] == 'S' || map[j] == 'N' || map[j] == 'W' || map[j] == 'E')
		count++;
	if (map[j] != '1' && map[j] != '0' && map[j] != ' ' && map[j] != 'S'
		&& map[j] != 'N' && map[j] != 'W' && map[j] != 'E')
		error_msg("Oops!Invalid Character in Map!\n");
	return (count);
}

void	check_endof_next_line(char **map, size_t i, size_t j)
{
	if (map[i][j] == '\0')
	{
		if (map[i + 1] && ft_strlen(map[i + 1]) > j - 1)
		{
			if (map[i + 1] && map[i + 1][j - 1] != '\0' && map[i + 1][j
				- 1] != '1')
			{
				if (map[i + 1][j] != '1')
					error_msg("=##===Oops!Map Has error!\n");
			}
		}
	}
}

size_t	map_size(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
void	init_tpars1(t_pars1 *p)
{
	p->i = 0;
	p->j = 0;
	p->count = 0;
	p->count2 = 0;
	p->k = 0;
}
void	map_checking(char **map)
{
	t_pars1	p;

	init_tpars1(&p);
	p.count2 = map_size(map);
	check_first_line(map[p.i]);
	while (map[p.i])
	{
		p.j = skip_space(map[p.i]);
		p.k = p.j;
		check_last_line(map[p.i], p.i, p.count2);
		while (map[p.i][p.j])
		{
			p.count = check_line(map[p.i], p.k, p.j, p.count);
			if (map[p.i][p.j] == '0')
				check_around_zero(map, p.i, p.j);
			p.j++;
		}
		check_endof_next_line(map, p.i, p.j);
		p.i++;
	}
	if (p.count != 1)
		error_msg("***Oops!Invalid Character in Map!\n");
}
