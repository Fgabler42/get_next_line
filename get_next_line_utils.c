/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:26:06 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/05 16:31:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
		{
			return ((char *) str + i);
		}
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) str + i);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*f;

	f = (char *)s;
	while (n--)
	{
		*f++ = '\0';
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void		*tmp;
	size_t		i;

	i = 0;
	if (nitems && (nitems * size) / nitems != size)
		return (NULL);
	tmp = malloc(size * nitems);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, size * nitems);
	return (tmp);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	new = (char *)ft_calloc(ft_strlen(s1)
			+ ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	if (s1)
		return (free((void *)s1), s1 = NULL, new);
	else
		return (free((void *)s1), new);
}
