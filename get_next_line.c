/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:15:02 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/16 18:26:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char static	*buffer;
	size_t		i;
	size_t		count;

	i = 0;
	buffer = 
	buffer[BUFFER_SIZE + 1] = '\0';
	count = 1;
	while ()
	{
		count = read(fd, buffer, BUFFER_SIZE);
		printf("%s", buffer);
		while (i < BUFFER_SIZE)
		{
			buffer[i] = tmp[i];
			i++;
		}
	}

	printf("%s", tmp);
	return (tmp);
}


int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	return (0);
}
