/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:09:12 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/18 20:04:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11000
# endif

# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

int		isitn(char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
