/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <fritzgabler@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:46:08 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/02 23:18:30 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_text_from_file(int fd, char *buffer)
{
	int		bytread;
	char	*buff;

	buff = ft_calloc_mod(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (free(buffer), NULL);
	bytread = 1;
	while (bytread > 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		bytread = read(fd, buff, BUFFER_SIZE);
		if (bytread == -1)
			return (free(buff), buff = NULL, free(buffer), NULL);
		if (bytread != 0)
			buffer = ft_strjoin_mod(buffer, buff);
		if (buffer && ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buff), buff = NULL, buffer);
}

static char	*copy_line(char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	len = 0;
	i = -1;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (ft_strchr(buffer, '\n'))
		len++;
	tmp = (char *) ft_calloc_mod(len + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (buffer[++i])
		tmp[i] = buffer[i];
	return (tmp);
}

static char	*update_buffer(char *buffer)
{
	int		first;
	int		back;
	char	*new_buffer;

	first = 0;
	back = 0;
	if (!buffer)
		return (free(buffer), NULL);
	while (buffer[back] != '\n' && buffer[back])
		back++;
	if (!buffer[back])
		return (free(buffer), NULL);
	if (buffer[back] == '\n' && buffer[back])
		back++;
	new_buffer = (char *) ft_calloc_mod(ft_strlen(buffer) - back, sizeof(char));
	if (new_buffer == NULL)
		return (free(buffer), free(new_buffer), NULL);
	while (buffer[back])
		new_buffer[first++] = buffer[back++];
	return (free(buffer), new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret;

	buffer = get_text_from_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	ret = copy_line(buffer);
	if (ret == NULL)
		return (NULL);
	buffer = update_buffer(buffer);
	if (buffer == NULL)
		return (NULL);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("text.txt", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// system("leaks a.out");
// 	close(fd);
// 	return (0);
// }
