/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:37:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/24 18:24:28 by fgabler          ###   ########.fr       */
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

	protect = 1;
	ft_bzero(buffer, BUFFER_SIZE);
	while (isitn(buffer, '\n'))
	{
		protect = read(fd, buffer, BUFFER_SIZE);
		if (protect == -1)
		{
			if (text)
			{
				free(text);
				text = NULL;
			}
			return (NULL);
		}
		if (protect == 0)
			return (text);
		// buffer[protect] = '\0';
		text = ft_strjoin(text, buffer);
	}
	return (text);
}

static char	*copy_clear_text(char *text, char *ret)
{
	int		i;
	int		j;
	size_t	count;

	i = -1;
	j = 0;
	count = ft_strlen(text);
	ret = malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (free(text), NULL);
	ret[count] = '\0';
	while (text[++i] != '\n' && text != NULL && text[i])
		ret[i] = text[i];
	if (text[i] == '\n')
		ret[i] = text[i];
	while (text[++i])
		text[j++] = text[i];
	text[j] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*text = NULL;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = NULL;
	text = get_text(text, fd);
	if (text == NULL)
		return (NULL);
	ret = copy_clear_text(text, ret);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// system("leaks a.out");
	close(fd);
	return (0);
}
