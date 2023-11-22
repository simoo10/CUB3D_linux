/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: met-tahe <met-tahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:48:19 by met-tahe          #+#    #+#             */
/*   Updated: 2023/11/22 22:48:21 by met-tahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	ft_mystrlen(char *r, char e)
{
	size_t	b;

	b = 0;
	while (r[b] && r[b] != e)
		b++;
	return (b);
}

static char	*copie(const char *s1, char d)
{
	char	*t;
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_mystrlen((char *)s1, d);
	t = malloc(len + 1);
	if (!t)
		return (0);
	while (s1[j] && s1[j] != d)
	{
		t[j] = s1[j];
		j++;
	}
	t[j] = 0;
	return (t);
}

static size_t	lencount(char *t1, char n)
{
	size_t	k;
	size_t	count;

	count = 0;
	k = 0;
	while (t1[k])
	{
		while (t1[k] == n && t1[k])
			k++;
		if (t1[k])
			count++;
		while (t1[k] != n && t1[k])
			k++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	z;
	size_t	finl;

	if (!s)
		return (0);
	finl = lencount((char *)s, c);
	i = 0;
	z = 0;
	p = (char **)malloc(sizeof(char *) * (finl + 1));
	if (!p)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			p[z++] = copie((char *)s + i, c);
		while (s[i] && s[i] != c)
			i++;
	}
	p[z] = 0;
	return (p);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
