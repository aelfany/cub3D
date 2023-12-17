/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:52:40 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/15 12:52:40 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parse_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->defmap && cub->defmap[i])
	{
		j = 0;
		while (cub->defmap[i][j])
		{
			if ((cub->defmap[i][j] == 'N' || cub->defmap[i][j] == 'S'
				|| cub->defmap[i][j] == 'W' || cub->defmap[i][j] == 'E')
				&& !player_valid(cub, i, j))
				ft_error("Invalid map player is not \
				fenced by valid elements!");
			j++;
		}
		i++;
	}
}

void	parse_empty_line(t_cub *cub)
{
	int	index;

	index = 0;
	while (cub->map && cub->map[index])
	{
		if (cub->map[index][0] == '\0')
			ft_error("Invalid map: Empty line in map");
		index++;
	}
}

void	duplicates(char **str, char c)
{
	int	index;
	int	flag;
	int	j;

	index = 0;
	flag = 0;
	while (str[index])
	{
		j = 0;
		while (str[index][j])
		{
			if (str[index][j] == c)
				flag++;
			j++;
		}
		index++;
	}
	if (flag > 1)
		ft_error("Invalid elements");
}

char	**take_path(char *str, t_gar **gar)
{
	char	**ptr;

	ptr = ft_split2(str, " \t\r");
	insert(gar, ptr);
	return (&ptr[1]);
}

t_gar	*store_it(t_cub *cub)
{
	t_gar	*gar;
	int		index;

	index = 0;
	gar = NULL;
	while (cub->allmap[index])
	{
		if (my_strstr(cub->allmap[index], "F"))
			cub->f = cub->allmap[index];
		else if (my_strstr(cub->allmap[index], "C"))
			cub->c = cub->allmap[index];
		else if (my_strstr(cub->allmap[index], "NO"))
			cub->no = *take_path(cub->allmap[index], &gar);
		else if (my_strstr(cub->allmap[index], "SO"))
			cub->so = *take_path(cub->allmap[index], &gar);
		else if (my_strstr(cub->allmap[index], "WE"))
			cub->we = *take_path(cub->allmap[index], &gar);
		else if (my_strstr(cub->allmap[index], "EA"))
			cub->ea = *take_path(cub->allmap[index], &gar);
		index++;
	}
	if (!cub->f || !cub->c || !cub->no
		|| !cub->so || !cub->ea || !cub->we)
		ft_error("Could not load Path");
	return (gar);
}
