/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <fritzgabler@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:49:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/01 17:56:12 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str1);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc_mod(size_t nitems, size_t size)

#endif
