/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:11:52 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/14 17:20:02 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_error(char *s)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(s, 1);
	write (1, "\n", 1);
	exit(0);
}

static int	words_counter(char *s, char *c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(c, s[i]))
			i++;
		else
		{
			words++;
			while (s[i] != '\0' && !ft_strchr(c, s[i]))
				i++;
		}
	}
	return (words);
}

static char	**free_mem2(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	return (NULL);
}

char	**ft_split2(char *s, char *c)
{
	size_t		word_len;
	char		**split;
	size_t		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	split = (char **)malloc((words_counter(s, c) + 1) * sizeof(*split));
	if (!split)
		return (free(split), NULL);
	while (*s != '\0')
	{
		while (*s && ft_strchr(c, *s))
			s++;
		word_len = 0;
		while (s[word_len] && !ft_strchr(c, s[word_len]))
			word_len++;
		if (word_len != 0)
			split[i++] = ft_substr(s, 0, word_len);
		if (word_len != 0 && split[i - 1] == 0)
			return (free_mem2(split));
		s += word_len;
	}
	split[i] = NULL;
	return (split);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			x;
	unsigned int	z;

	x = 0;
	if (!s)
		return (0);
	z = ft_strlen(s);
	if (start >= z)
		return (ft_strdup(""));
	if (len > z)
		len = z - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (x < len && s[start])
	{
		sub[x] = s[start];
		start++;
		x++;
	}
	sub[x] = '\0';
	return (sub);
}
