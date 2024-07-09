/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:45:06 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/07/08 15:47:48 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stnext[32767];
	char		*res;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (stnext[fd] != NULL)
		{
			free(stnext[fd]);
			stnext[fd] = NULL;
		}
		return (NULL);
	}
	stnext[fd] = read_line(fd, stnext[fd]);
	res = write_line(stnext[fd]);
	stnext[fd] = rest_of_line(stnext[fd]);
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
	int fd1 = open("prueba.txt", O_RDONLY);
	printf("Is is over now?:\n");
	for(int i = 0; i < 3; i++) {
		printf("%s", get_next_line(fd1));
	}
	printf("\n\n");

	printf("Last kiss:\n");
	int fd2 = open("prueba2.txt", O_RDONLY);
	for(int i = 0; i < 3; i++) {
		printf("%s", get_next_line(fd2));
	}
	printf("\n\n");

	printf("Bejeweled:\n");
	int fd3 = open("prueba3.txt", O_RDONLY);
	for(int i = 0; i < 3; i++) {
		printf("%s", get_next_line(fd3));
	}
	printf("\n\n");

	printf("You're on your own, kid:\n");
	int fd4 = open("prueba4.txt", O_RDONLY);
	for(int i = 0; i < 4; i++) {
		printf("%s", get_next_line(fd4));
	}
	printf("\n\n");

	printf("Haunted:\n");
	int fd5 = open("prueba5.txt", O_RDONLY);
	for(int i = 0; i < 3; i++) {
		printf("%s", get_next_line(fd5));
	}
	printf("\n\n");

	printf("The last time: \n");
	int fd6 = open("prueba6.txt", O_RDONLY);
	for(int i = 0; i < 4; i++) {
		printf("%s", get_next_line(fd6));
	}
	printf("\n\n");

	printf("Out of the woods:\n");
	int fd7 = open("prueba7.txt", O_RDONLY);
	for(int i = 0; i < 4; i++) {
		printf("%s", get_next_line(fd7));
	}
	printf("\n\n");

	printf("August:\n");
	int fd8 = open("prueba8.txt", O_RDONLY);
	for(int i = 0; i < 4; i++) {
		printf("%s", get_next_line(fd8));
	}
	printf("\n\n");

	printf("How did it end?:\n");
	int fd9 = open("prueba9.txt", O_RDONLY);
	for(int i = 0; i < 8; i++) {
		printf("%s", get_next_line(fd9));
	}
	printf("\n\n");

	printf("Clean:\n");
	int fd10 = open("prueba10.txt", O_RDONLY);
	for(int i = 0; i < 4; i++) {
		printf("%s", get_next_line(fd10));
	}
	return (0);
} */