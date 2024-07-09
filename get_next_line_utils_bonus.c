/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:08:10 by marvin            #+#    #+#             */
/*   Updated: 2024/07/09 13:08:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			len;
	size_t			i;

	len = count * size;
	ptr = malloc(len * sizeof(char));
	i = 0;
	if (ptr == 0)
	{
		return (0);
	}
	while (i < len)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	pos;
	size_t	pos2;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	pos = 0;
	while (pos < ft_strlen(s1))
	{
		res[pos] = s1[pos];
		pos++;
	}
	pos2 = 0;
	while (pos2 < ft_strlen(s2))
	{
		res[pos] = s2[pos2];
		pos++;
		pos2++;
	}
	res[pos] = '\0';
	return (res);
}

int	ft_endl(char *s)
{
	size_t	i;
	
	i = 0;
	while(s[i] != 0)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		cont++;
		i++;
	}
	return (cont);
}