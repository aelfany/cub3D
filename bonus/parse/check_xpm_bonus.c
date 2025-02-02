/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:45:51 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 21:40:05 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	process_line(t_cub *cub, int i, int *count)
{
	int	j;

	j = -1;
	while (cub->allmap[i][++j])
	{
		j += 2;
		if (is_space(cub->allmap[i][j]))
			j++;
		if (cub->allmap[i][j])
			break ;
		else
			ft_error("Error\nInvalid Path");
	}
	(*count)++;
}

void	parse_xpmfiles(t_cub *cub)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (cub->allmap[++i])
	{
		if ((cub->allmap[i][2] && cub->allmap[i][2] == ' ')
			&& (my_strstr(cub->allmap[i], "NO")
			|| my_strstr(cub->allmap[i], "SO")
			|| my_strstr(cub->allmap[i], "WE")
			|| my_strstr(cub->allmap[i], "EA")))
		{
			process_line(cub, i, &count);
		}
	}
	if (count != 4)
		ft_error("Invalid Path");
}

void	parse_map(t_cub *cub)
{
	int	i;
	int	flag;
	int	j;

	i = -1;
	flag = 0;
	while (cub->defmap && cub->defmap[++i])
	{
		j = -1;
		while (cub->defmap[i][++j])
		{
			if (is_space(cub->defmap[i][j]))
				j++;
			else if (cub->defmap[i][j] == 'N' || cub->defmap[i][j] == 'S'
				|| cub->defmap[i][j] == 'W' || cub->defmap[i][j] == 'E')
				flag++;
			else if (cub->defmap[i][j] != '0' && cub->defmap[i][j] != '1'
				&& cub->defmap[i][j] != '*')
				ft_error("Invalid map: unknown character");
		}
	}
	if (flag > 1 || flag == 0)
		ft_error("Invalid map");
}

void	insert(t_gar **root, char **item)
{
	t_gar	*temp;
	t_gar	*ptr;

	temp = malloc(sizeof(t_gar));
	if (!temp)
		exit(1);
	temp -> ptr = item;
	temp -> next = NULL;
	if (*root == NULL)
		*root = temp;
	else
	{
		ptr = *root;
		while (ptr-> next != NULL)
			ptr = ptr->next;
		ptr -> next = temp;
	}
}
