/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:42:23 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 19:32:41 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	free_string(char **ptr)
{
	int	a;

	a = 0;
	while (ptr[a])
		free(ptr[a++]);
	free(ptr);
}

void	normilize_angle(t_cub *mlx)
{
	while (mlx->ray < 0)
		mlx->ray += (M_PI * 2);
	while (mlx->ray > (M_PI * 2))
		mlx->ray -= (M_PI * 2);
}

double	move_player(char der)
{
	if (der == 'N')
		return ((M_PI * 3) / 2);
	if (der == 'E')
		return (0.0);
	if (der == 'S')
		return (M_PI / 2);
	return (M_PI);
}

int	ray_side(double ray_angle)
{
	if (ray_angle >= 0.0 && ray_angle <= M_PI / 2)
		return (RIGHT_DOWN);
	if (ray_angle > M_PI / 2 && ray_angle <= M_PI)
		return (LEFT_DOWN);
	if (ray_angle > M_PI && ray_angle <= M_PI + (M_PI / 2))
		return (LEFT_UP);
	return (RIGHT_UP);
}

int	maplen(char **str, int x)
{
	int	a;

	a = 0;
	if (x == 1)
		while (str[a])
			a++;
	else
		while ((*str)[a])
			a++;
	return (a);
}
