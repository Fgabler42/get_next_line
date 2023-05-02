/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <fritzgabler@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:26:06 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/05/01 18:02:44 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

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

void	*ft_calloc_mod(size_t nitems, size_t size)
{
	void	*tmp;
	int		i,

	i = 0;
	if (nitems && (nitems * size) / nitems != size)
		return (NULL);
	tmp = malloc(size * nitems);
	if (!tmp)
		return (NULL);
	while (size--)
		tmp[i++] = '\0';
	return (tmp);
}

char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	new = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	return (free(s1), s1 = NULL, new);
}