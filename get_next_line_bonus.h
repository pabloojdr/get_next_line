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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/// @brief 
/// @param fd 
/// @return 
char	*get_next_line(int fd);

/// @brief Contigoudly allocates enough space for count
/// objects that are size bytes of memory each and
/// returns a pointer to the allocated memory. The allocated 
/// memory is filled with bytes of value zero
/// @param count Number of objects
/// @param size Size in bytes of each object
/// @return If successful, returns a pointer to allocated
/// memory. If there is an error, it returns a NULL pointer
/// and set errno to ENOMEM
void    *ft_calloc(size_t count, size_t size);

/// @brief Devuelve un nuevo string, formado por la
/// concatenación de s1 y s2 
/// @param s1 Primer string
/// @param s2 String a añadir a s1
/// @return Un nuevo string con s2 concatenado a s1
char	*ft_strjoin(const char *s1, const char *s2);

/// @brief Llama a la funcion ft_strjoin asegurandose de liberar memoria
/// @param s1 Cadena a la que se va a concatenar
/// @param s2 Cadena concatenada
/// @return La cadena resultante de la concatenacion
char	*ft_join(char *s1, char	*s2);

/// @brief Comprueba si en la cadena proporcionada hay un salto de linea
/// @param s Cadena que recorrer
/// @return 1 si hay un salto de linea, 0 en otro caso
int     ft_endl(char *s);

/// @brief Calcula la longitud de una cadena.
/// @param s Cadena de la que se quiere saber la longitud
/// @return Numero de caracteres que preceden al caracter nulo
size_t	ft_strlen(const char *s);

#endif