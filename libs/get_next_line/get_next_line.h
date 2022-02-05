/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:59:44 by mnaimi            #+#    #+#             */
/*   Updated: 2021/11/28 21:48:00 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Mandatory includes */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/* Macros */
# define TRUE 1
# define FALSE 0

/* Prototypes */
char	*get_next_line(int fd, int buffer_size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);

#endif
