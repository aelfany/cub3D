/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:33:34 by otchekai          #+#    #+#             */
/*   Updated: 2023/02/16 13:48:01 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		index;
	char	*ptr;

	index = 1;
	ptr = malloc(BUFFER_SIZE + 1);
	if (!ptr)
		return (NULL);
	while (index > 0 && !ft_strchr(buffer, '\n'))
	{
		index = read(fd, ptr, BUFFER_SIZE);
		if (index < 0 || (index == 0 && !buffer)
			|| (index == 0 && buffer[0] == 0))
			return (free(ptr), free(buffer), NULL);
		ptr[index] = '\0';
		buffer = ft_strjoin(buffer, ptr);
	}
	free(ptr);
	return (buffer);
}

char	*ft_stock(char *str)
{
	int		index;
	char	*ptr;
	int		secindex;

	index = 0;
	secindex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	ptr = malloc(index + 1);
	if (!ptr)
		return (free(str), NULL);
	while (str[secindex] && index > secindex)
	{
		ptr[secindex] = str[secindex];
		secindex++;
	}
	ptr[secindex] = '\0';
	return (ptr);
}

char	*ft_beyondstock(char *str)
{
	int		index;
	char	*ptr;
	int		size;
	int		secindex;

	index = 0;
	secindex = 0;
	while (str[index] && str[index] != '\n')
		index++;
	size = ft_strlen(str);
	if (size == index)
		return (free(str), NULL);
	ptr = malloc((size - index) + 1);
	if (!ptr)
		return (free(str), NULL);
	index++;
	while (str[index])
		ptr[secindex++] = str[index++];
	ptr[secindex] = '\0';
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*stats;
	char			*notsta;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stats = ft_read(fd, stats);
	if (!stats)
		return (NULL);
	notsta = ft_stock(stats);
	stats = ft_beyondstock(stats);
	return (notsta);
}
