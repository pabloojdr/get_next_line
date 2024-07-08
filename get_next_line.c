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
	if(rest[0] == '\0')
	{
		
	}
}
