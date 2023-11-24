/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:30 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/24 16:43:16 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (map[p.i][p.j] == '0' || player_check(map[p.i][p.j]))
				check_around_zero(map, p.i, p.j);
			p.j++;
		}
		check_endof_next_line(map, p.i, p.j);
		p.i++;
	}
	if (p.count != 1)
		error_msg("***Oops!Invalid Character in Map!\n");
}
