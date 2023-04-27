/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:37:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/27 19:32:20 by fgabler          ###   ########.fr       */
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

	protect = 1;
	while (protect)
	{
		protect = read(fd, buffer, BUFFER_SIZE);
		if (protect == 0)
			return ;
		if (protect > 0)
			buffer[protect] = '\0';
		else if (protect == -1)
			return (free_it(*text));
		if (!isit_init(buffer, '\n'))
		{
			*text = ft_strjoin(*text, buffer);
			break ;
		}
		*text = ft_strjoin(*text, buffer);
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
	printf("%p\n", text);
	if (text == NULL || isit_init(text, 0))
		return (free_it(text), NULL);
	ret = copy_clear_text(text, ret);
	if (ret == NULL)
		return (free_it(ret), free_it(text), NULL);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	char	a[10];

// 	fd = open("text.txt", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// system("leaks a.out");
// 	close(fd);
// 	return (0);
// }
