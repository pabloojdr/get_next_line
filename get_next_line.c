/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:12:47 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/05/16 12:21:47 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*res;
	size_t			i;
	static char		*aux;
	static size_t	pos;

	if (pos < BUFFER_SIZE)
		aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = ft_strdup("");
		
	if (!aux)
		return (0);
	i = 1;
	while (i != 0)
	{
		i = read(fd, aux, BUFFER_SIZE);
		if (i < 0)
		{
			free(res);
			return (NULL);
		}
		aux[i] = '\0';
		pos = 0;
		while (aux[pos] != '\0')
		{
			if (ft_isendl(aux[pos]))
			{
				i = 0;
				break ;
			}
			pos++;
		}
		res = ft_strjoin(res, aux, pos + 1);
	}
	return (res);
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){
	int fd = open("prueba.txt", O_RDONLY);
	char *cadena = get_next_line(fd);
	printf("%s", cadena);
	cadena = get_next_line(fd);
	printf("%s", cadena);
	return (0);
}