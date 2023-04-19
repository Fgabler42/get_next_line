/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:57:12 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/19 14:47:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isitn(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (0);
		i++;
	}
	if (str[i] == (char) c)
		return (0);
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// char	*ft_strdup(const char *str1)
// {
// 	char			*tmp;
// 	unsigned int	i;

// 	i = 0;
// 	tmp = (char *) malloc((ft_strlen(str1) + 1));
// 	if (!tmp)
// 		return (0);
// 	while (str1[i])
// 	{
// 		tmp[i] = str1[i];
// 		i++;
// 	}
// 	return (tmp);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (free (s1), new);
}
