/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:37:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/18 20:24:51 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static char	*get_text(char *text, int fd)
{
	int		protect;
	char	buffer[BUFFER_SIZE + 1];

	protect = 0;
	buffer[BUFFER_SIZE] = '\0';
	text = (char *)malloc(1);
	if (!text)
		return (NULL);
	while (isitn(text, '\n'))
	{
		protect = read(fd, buffer, BUFFER_SIZE);
		if (protect == -1)
			return (NULL);
		text = ft_strjoin(text, buffer);
	}
	return (text);
}

static void	copy_claer_text(char *text, char *ret)
{
	int		i;
	int		j;
	size_t	count;

	i = 0;
	j = 0;
	count = ft_strlen(text);
	ret = (char *)malloc(count + 1);
	if (!ret)
		return ;
	ret[count] = '\0';
	if (!ret)
	{
		free(ret);
		return ;
	}
	while (text[i])
	{
		ret[i] = text[i];
		i++;
	}
	ret[i] = text[i];
	while (text[i])
		text[j++] = text[i++];
	text[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*ret;

	text = get_text(text, fd);
	copy_claer_text(text, ret);
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
