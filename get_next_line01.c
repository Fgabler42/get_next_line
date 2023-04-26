/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:37:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/26 21:57:49 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

static void	free_it(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static void	get_text(char **text, int fd)
{
	int		protect;
	char	buffer[BUFFER_SIZE + 1];

	protect = read(fd, buffer, BUFFER_SIZE);
	while (protect)
	{
		if (protect == 0)
		{
			*text = ft_strjoin(*text, buffer);
			return ;
		}
		if (protect == -1)
			return (free_it(*text));
		buffer[protect] = '\0';
		if (!isit_n(buffer))
		{
			*text = ft_strjoin(*text, buffer);
			break ;
		}
		*text = ft_strjoin(*text, buffer);
		protect = read(fd, buffer, BUFFER_SIZE);
	}
}

static char	*copy_clear_text(char *text, char *ret)
{
	int		i;
	int		j;
	size_t	count;

	i = -1;
	j = 0;
	count = ft_strlen(text);
	ret = (char *) malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (free(text), free_it(ret), NULL);
	ft_bzero(ret, count + 1);
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

	ret = NULL;
	get_text(&text, fd);
	if (text == NULL)
		return (NULL);
	ret = copy_clear_text(text, ret);
	if (ret == NULL)
		return (NULL);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	// system("leaks a.out");
// 	close(fd);
// 	return (0);
// }
