/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:46:08 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/06 11:45:35 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// free_it: is a function that frees memory allocated
// to a string, but only if the string is not NULL.

static void	free_it(char *str)
{
	if (str != NULL)
		free((void *)str);
}

// get_text_from_file : is a function that reads text from
// a file descriptor and returns
// it as a character string.

static char	*get_text_from_file(int fd, char *buffer)
{
	int		bytread;
	char	*buff;

	buff = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	bytread = 1;
	while (bytread > 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		bytread = read(fd, buff, BUFFER_SIZE);
		if (bytread == -1)
			return (free_it(buff), free_it(buffer), NULL);
		if (bytread != 0)
			buffer = ft_strjoin_mod(buffer, buff);
		if (buffer && ft_strchr(buffer, '\n'))
			break ;
	}
	return (free_it(buff), buffer);
}

// This function copies a line of text from a buffer and
// returns it as a new string. The function takes in a
// buffer as its argument.

static char	*copy_line(char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	i = -1;
	if (!buffer || !buffer[0])
		return (free_it(buffer), NULL);
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len] == '\n')
		len++;
	tmp = (char *) ft_calloc(len + 1, sizeof(char));
	if (tmp == NULL)
		return (free_it(buffer), NULL);
	while (++i < len)
		tmp[i] = buffer[i];
	return (tmp);
}

// update_buffer: This is a helper function for read
// from a file descriptor, which updates the
// buffer used for reading. The function takes
// two arguments: buffer, which represents the
// buffer used for reading, and ret, which
// represents a pointer to a string that will be
// returned from the main function.

static char	*update_buffer(char *buffer, char *ret)
{
	int		first;
	int		back;
	char	*new_buffer;

	first = 0;
	back = 0;
	while (buffer[back] != '\n' && buffer[back])
		back++;
	if (buffer[back] == '\0')
		return (free_it(buffer), NULL);
	if (buffer[back] == '\n' && buffer[back + 1] == '\0')
		return (free_it(buffer), NULL);
	new_buffer = (char *) ft_calloc((ft_strlen(buffer) - back), sizeof(char));
	if (buffer[back] == '\n' && buffer[back])
		back++;
	if (new_buffer == NULL)
		return (free_it(ret), free_it(buffer), NULL);
	while (buffer[back])
		new_buffer[first++] = buffer[back++];
	return (free_it(buffer), new_buffer);
}

// get_next_line: is a function that reads and returns the
// next line rom a file descriptor. The function takes
// in a file descriptor as its argument.

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret;

	ret = NULL;
	buffer = get_text_from_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	ret = copy_line(buffer);
	if (ret == NULL)
		return (NULL);
	buffer = update_buffer(buffer, ret);
	return (ret);
}

// int main: is a main function that tests the get_next_line()
// function by reading lines from a file descriptor
// and printing them to the console.

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDWR);
// 	printf("first:%s", get_next_line(fd));
// 	printf("secont%s", get_next_line(fd));
// 	printf("tree:%s", get_next_line(fd));
// 	printf("four:%s", get_next_line(fd));
// 	printf("five:%s", get_next_line(fd));
// 	printf("six :%s", get_next_line(fd));
// 	printf("seven:%s", get_next_line(fd));
// 	printf("eight:%s", get_next_line(fd));
// 	printf("nine:%s", get_next_line(fd));
// 	printf("ten:%s", get_next_line(fd));
// 	printf("eleven:%s", get_next_line(fd));
// 	// system("leaks a.out");
// 	close(fd);
// 	return (0);
// }