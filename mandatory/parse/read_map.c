/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:37:12 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/15 19:56:25 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	fun_check(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (!is_space(str[a]))
			return (1);
		a++;
	}
	return (0);
}

char	**defmap(t_cub *cub)
{
	int		index;
	int		j;
	char	**ptr;

	index = -1;
	if (!cub->map)
		return (NULL);
	ptr = ft_calloc(sizeof(char *), cub->map_height + 1);
	if (!ptr)
		return (NULL);
	while (cub->map[++index])
	{
		ptr[index] = ft_calloc(sizeof(char), cub->map_width + 1);
		if (!ptr[index])
			return (free_string(ptr), NULL);
		j = -1;
		while (++j < cub->map_width)
		{
			if (j < ft_strlen(cub->map[index]))
				ptr[index][j] = cub->map[index][j];
			else
				ptr[index][j] = '*';
		}
	}
	return (ptr[index] = NULL, ptr);
}

void	ones_length(t_cub *cub)
{
	int	index;

	index = 0;
	while (cub->map && cub->map[index])
		index++;
	cub->ones_length = index;
}

char	**devide_map(t_cub *cub)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		if (cub->allmap[index][0] == '\0')
		{
			index++;
			continue ;
		}
		if (ft_strchr(cub->allmap[index], '1') && count == 6)
			return (&cub->allmap[index]);
		count++;
		index++;
	}
	return (NULL);
}
