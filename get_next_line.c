/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:15:02 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/18 20:03:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static void	cleanstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		while (str[i])
			str[i++] = '\0';
	}
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int			count;

	buffer[BUFFER_SIZE] = '\0';
	tmp = (char *)malloc(1);
	if (!tmp)
		free(tmp);
	while (isitn(tmp, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			free(buffer);
		tmp = ft_strjoin(tmp, buffer);
	}
	cleanstr(tmp);
	return (tmp);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
