/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:05:01 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/05/14 15:21:21 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2, size_t count)
{
	char	*res;
	size_t	pos;
	size_t	pos2;

	res = malloc((ft_strlen(s1) + count + 1) * sizeof(char));
	if (res == NULL)
		return (res);
	pos = 0;
	while (pos < ft_strlen(s1))
	{
		res[pos] = s1[pos];
		pos++;
	}
	pos2 = 0;
	while (pos2 < count)
	{
		res[pos] = s2[pos2];
		pos++;
		pos2++;
	}
	res[pos] = '\0';
	return (res);
}

int	ft_isendl(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

void	ft_free(char *s)
{
	int	pos;

	pos = 0;
	while (s[pos] != '\0')
		free(s[pos]);
	free(s);
}
