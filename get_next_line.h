/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampoy- <pcampoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:18:27 by pcampoy-          #+#    #+#             */
/*   Updated: 2024/05/14 15:19:54 by pcampoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

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

/// @brief Comprueba si el caracter es final de línea
/// @param c Caracter a comprobar
/// @return 1 si es final de línea, 0 en caso contrario
int		ft_isendl(char c);

/// @brief Libera la memoria asignada
/// @param s Cadena que hay que liberar de memoria
void	ft_free(char *s);

#endif