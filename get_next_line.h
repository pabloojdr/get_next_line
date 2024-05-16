/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:18:27 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/05/14 15:53:37 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/// @brief 
/// @param fd 
/// @return 
char	*get_next_line(int fd);

/// @brief Devuelve un nuevo string, formado por la
/// concatenación de s1 y s2 
/// @param s1 Primer string
/// @param s2 String a añadir a s1
/// @param count Cantidad de palabras a añadir
/// @return Un nuevo string con s2 concatenado a s1
char	*ft_strjoin(const char *s1, const char *s2, size_t count);

/// @brief Calcula la longitud de una cadena.
/// @param s Cadena de la que se quiere saber la longitud
/// @return Numero de caracteres que preceden al caracter nulo
size_t	ft_strlen(const char *s);

/// @brief Comprueba si el caracter es final de línea
/// @param c Caracter a comprobar
/// @return 1 si es final de línea, 0 en caso contrario
int		ft_isendl(char c);

/// @brief Allocates sufficient memory for a copy of the 
/// string s1, does the copy, and returns a pointer to it.
/// @param s1 String to be duplicated
/// @return If successful, returnrs a pointer to the new
/// duplicated string. If insufficient memory is available,
/// NULL is returned
char	*ft_strdup(const char *s1);

#endif