/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:05 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:05 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
