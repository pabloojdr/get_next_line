/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:12:47 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/05/14 15:18:06 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*res;
	size_t			i;
	char			*aux;
	size_t			pos;

	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!aux)
		return (0);
	i = 1;
	while (i != 0)
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i < 0)
			return (ft_free(res), 0);
		aux[i] = '\0';
		pos = 0;
		while (aux[pos] != '\0')
		{
			if (ft_isendl(aux[pos]))
				break ;
			pos++;
		}
		res = ft_strjoin(res, aux, pos + 1);
	}
	return (res);
}
