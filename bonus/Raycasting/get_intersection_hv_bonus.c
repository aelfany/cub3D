/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection_hv_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:36:50 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 19:21:43 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	check_wall(t_cub *mlx, int x, int y)
{
	if (y < 0 || y >= maplen(mlx->defmap, 1) \
		|| x < 0 || x >= maplen(mlx->defmap, 0))
		return (1);
	if (mlx->defmap[y][x] == '1')
		return (1);
	return (0);
}

double	intersection_h_ay(t_cub *mlx, int side)
{
	double	a;

	a = floor(mlx->y / SQR_SIZE) * SQR_SIZE;
	if (side == RIGHT_DOWN || side == LEFT_DOWN)
		return (a + SQR_SIZE);
	return (a);
}

double	intersection_h_ax(t_cub *mlx, int side)
{
	return (mlx->x + (intersection_h_ay(mlx, side) - mlx->y) / tan(mlx->ray));
}

double	intersection_v_ax(t_cub *mlx, int side)
{
	double	a;

	a = (floor(mlx->x / SQR_SIZE) * SQR_SIZE);
	if (side != LEFT_UP && side != LEFT_DOWN)
		return (a + SQR_SIZE);
	return (a);
}

double	intersection_v_ay(t_cub *mlx, int side)
{
	return (mlx->y + (intersection_v_ax(mlx, side) - mlx->x) * tan(mlx->ray));
}
