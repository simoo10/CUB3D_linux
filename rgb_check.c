/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:35 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:37 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
