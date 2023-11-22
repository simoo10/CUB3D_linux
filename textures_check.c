/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:41 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:42 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no(char *v)
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

int	check_so(char *v)
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

int	check_we(char *v)
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

int	check_ea(char *v)
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

int	check_f(char *v)
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
