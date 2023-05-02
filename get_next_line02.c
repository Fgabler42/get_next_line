/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <fritzgabler@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:46:08 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/01 17:55:41 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_text_from_file(int fd, char *buffer)
{
	int		bytread;
	char	*buff[BUFFER_SIZE];

	bytread = read(fd, buff, BUFFER_SIZE);
	while (ft_strchr(buff, '\n') || bytread)
	{
		if (bytread == -1)
			return (free(buff), NULL);
		if (bytread == 0)
			return (ft_strjoin(buffer, buff));
		if (ft_strchr (buffer, '\n'))
			return (buffer);
	}
}

static char	*copy_line(char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	while (ft_strchr(tmp, '\n') && buffer[len])
		len++;
	tmp = ft

}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*ret;

	buffer = get_text_from_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	ret = copy_line();

}