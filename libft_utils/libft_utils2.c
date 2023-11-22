/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:48:22 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:48:22 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *)malloc((sizeof(char) * ft_strlen(src)) + 1);
	if (!dest)
		return (0);
	dest = ft_strcpy(dest, src);
	return (dest);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	k = ft_strlen(s);
	if (k < len)
		len = k;
	p = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s || !p)
		return (0);
	while (s[i] && i < start)
		i++;
	while (s[i] && i < start + len)
		p[j++] = s[i++];
	p[j] = 0;
	free(s);
	return (p);
}

int	ft_atoi(char *str)
{
	size_t	i;
	size_t	n;
	size_t	r;

	r = 0;
	i = 0;
	n = 0;
	if (str[i] == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			n = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i++] - '0';
		if ((long int)r > __LONG_MAX__ + (n == 1))
			error_msg("Error\n: Number is too big\n");
	}
	if (n)
		r = r * (-1);
	return (r);
}
