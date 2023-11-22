/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:23 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:24 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
