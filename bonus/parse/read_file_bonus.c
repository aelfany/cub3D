/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:26 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/15 22:54:55 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	checkmapextension(char *filename)
{
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".cub", 4) == 0)
		return ;
	else
		ft_error("extension error");
}

char	**read_map(t_cub *cub, char *av)
{
	char	*str;
	int		index;
	char	**ptr;
	int		fd;

	index = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error("File error");
	ptr = malloc((cub->map_height + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		ptr[index++] = str;
		str = get_next_line(fd);
	}
	ptr[index] = NULL;
	return (ptr);
}

void	map_height(t_cub *cub, char *name)
{
	int		fd;
	char	str;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_error("file error");
	cub->map_height = 0;
	while (read(fd, &str, 1))
	{
		if (str == '\n')
			cub->map_height++;
	}
	if (cub->map_height == 0)
		ft_error("Empty Map");
	cub->map_height++;
	close(fd);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
