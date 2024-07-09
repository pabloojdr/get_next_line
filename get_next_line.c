/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:44:31 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/07/08 19:28:49 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *nextl, char	*s)
{
	char	*res;

	res = ft_strjoin(nextl, s);
	free(nextl);
	return (res);
	
}

static char	*read_line(int fd, char *nextl)
{
	char	*res;
	int		i;

	i = 1;
	if (!nextl)
		nextl = ft_calloc(1, sizeof(char));
	res = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (i > 0)
	{
		i = read(fd, res, BUFFER_SIZE);
		if (i < 0)
		{
			free(res);
			return (NULL);
		}
		res[i] = '\0';
		nextl = ft_join(nextl, res);
		if (ft_endl(nextl) == 1)
			break ;
	}
	free(res);
	return (nextl);
}

static char	*write_line(char *nextl)
{
	char	*res;
	size_t	i;
	
	i = 0;
	while (nextl[i] != '\n' && nextl[i] != '\0')
		i++;
	res = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (nextl[i] != '\n' && nextl[i] != '\0')
	{
		res[i] = nextl[i];
		i++;
	}
	if (nextl[i] != '\0' && nextl[i] == '\n')
		res[i] = '\n';
	return (res);
}

static char	*rest_of_line(char *nextl)
{
	char	*res;
	size_t	i;
	size_t 	j;

	i = 0;
	j = 0;
	while (nextl[i] != '\0' && nextl[i] != '\n')
		i++;
	if (nextl[i] == '\0')
	{
		free(nextl);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(nextl) - i) + 1, sizeof(char));
	i++;
	while (nextl[i] != 0)
		res[j++] = nextl[i++];
	free(nextl);
	if (res[0] == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stnext = NULL;
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stnext != NULL)
		{
			free(stnext);
			stnext = NULL;
		}
		return (NULL);
	}
	stnext = read_line(fd, stnext);
	res = write_line(stnext);
	stnext = rest_of_line(stnext);
	if(res[0] == '\0')
		return(free(res), NULL);
	return (res);
}

/* #include <fcntl.h>
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
	cadena = get_next_line(fd);
	printf("%s", cadena);
	return (0);
} */