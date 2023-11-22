/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:20 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:22 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (check_no(v))
	{
		i = check_no(v);
		cub->no = take_paths(cub->no, v, &cub->count, i);
		return (0);
	}
	else if (check_so(v))
	{
		i = check_so(v);
		cub->so = take_paths(cub->so, v, &cub->count, i);
		return (0);
	}
	else if (check_ea(v))
	{
		i = check_ea(v);
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
	else if (check_we(v))
	{
		i = check_we(v);
		cub->we = take_paths(cub->we, v, &cub->count, i);
		return (0);
	}
	else if (check_c(v))
	{
		i = check_c(v);
		cub->c = take_paths(cub->c, v, &cub->count, i);
		return (0);
	}
	else if (check_f(v))
	{
		i = check_f(v);
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
