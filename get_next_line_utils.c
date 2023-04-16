/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:57:12 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/16 18:21:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isitn(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
		{
			return (0);
		}
		i++;
	}
	if (str[i] == (char) c)
		return (0);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str1)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *) malloc((ft_strlen(str1) + 1));
	if (!tmp)
		return (0);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	new[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	if (s1[i] == '\0' && s2[j] == '\0')
		return (free(new), ft_strdup(""));
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	return (new);
}
