/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:46:01 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:46:04 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
