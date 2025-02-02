/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   check_elemnts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:25 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/15 12:48:33 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	checkmap(t_cub *cub)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (cub->allmap[index])
	{
		if (my_strstr(cub->allmap[index], "F")
			|| my_strstr(cub->allmap[index], "C")
			|| my_strstr(cub->allmap[index], "NO")
			|| my_strstr(cub->allmap[index], "SO")
			|| my_strstr(cub->allmap[index], "WE")
			|| my_strstr(cub->allmap[index], "EA"))
			count++;
		index++;
	}
	if (count != 6)
		ft_error("Invalid elements");
}

void	processvalue(int i, int *j, t_cub *cub)
{
	cub->value = 0;
	while (cub->allmap[i][*j] && ft_isdigit(cub->allmap[i][*j]))
	{
		cub->value = cub->value * 10 + (cub->allmap[i][*j] - '0');
		(*j)++;
	}
	while (cub->allmap[i][*j] && (cub->allmap[i][*j] == ' '
		|| cub->allmap[i][*j] == '\t' || cub->allmap[i][*j] == '\r'))
		(*j)++;
	if (cub->value < 0 || cub->value > 255)
		ft_error("Invalid elements: values must be between 0 and 255");
	if (cub->allmap[i][*j] && cub->allmap[i][*j] != ','
		&& !ft_isdigit(cub->allmap[i][*j]))
		ft_error("Extra character found");
}

void	processrgbvalues(int i, int *j, t_cub *cub)
{
	int	*key_counter;
	int	*delimiter;

	key_counter = &cub->key_counter;
	delimiter = &cub->delimiter;
	while (cub->allmap[i][*j])
	{
		if ((cub->allmap[i][*j] == 'F' && is_space(cub->allmap[i][*j + 1])) ||
			(cub->allmap[i][*j] == 'C' && is_space(cub->allmap[i][*j + 1])))
		{
			(*key_counter)++;
			(*j)++;
		}
		else if (is_space(cub->allmap[i][*j]))
			(*j)++;
		else if (cub->allmap[i][*j] == ','
			&& ft_isdigit(cub->allmap[i][*j - 1])
			&& ft_isdigit(cub->allmap[i][++(*j)]) && (*delimiter)++ < 2)
			;
		else if (!ft_isdigit(cub->allmap[i][*j]))
			ft_error("Invalid elements");
		else
			processvalue(i, j, cub);
	}
}

void	parse_rgb(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->allmap[++i])
	{
		j = 0;
		cub->delimiter = 0;
		if (cub->allmap[i][0] == '\0')
			i++;
		if ((my_strstr(cub->allmap[i], "F") || my_strstr(cub->allmap[i], "C")))
		{
			processrgbvalues(i, &j, cub);
			cub->count++;
		}
		if (cub->count == 2)
		{
			if (cub->delimiter != 2 || cub->key_counter != 2)
				ft_error("Invalid elements");
			break ;
		}
	}
}

void	check_first(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->allmap[i])
	{
		if ((my_strstr(cub->allmap[i], "NO"))
			|| my_strstr(cub->allmap[i], "SO")
			|| my_strstr(cub->allmap[i], "WE")
			|| my_strstr(cub->allmap[i], "EA"))
			parse_xpmfiles(cub);
		else if ((my_strstr(cub->allmap[i], "F")
				|| my_strstr(cub->allmap[i], "C")))
			parse_rgb(cub);
		i++;
	}
}
