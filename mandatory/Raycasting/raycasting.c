/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:44:36 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/12 00:57:00 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_sum_intersection_horizontal(t_cub *mlx, t_info *hold)
{
	hold->h_y = intersection_h_ay(mlx, hold->side);
	hold->h_x = intersection_h_ax(mlx, hold->side);
	hold->tile = SQR_SIZE;
	if (hold->side == LEFT_UP || hold->side == RIGHT_UP)
		hold->tile = -hold->tile;
	hold->xa = SQR_SIZE / tan(mlx->ray);
	if (hold->side == LEFT_UP || hold->side == LEFT_DOWN)
		if (hold->xa > 0)
			hold->xa = -hold->xa;
	if (hold->side == RIGHT_UP || hold->side == RIGHT_DOWN)
		if (hold->xa < 0)
			hold->xa = -hold->xa;
	while (1)
	{
		if (hold->side == LEFT_UP || hold->side == RIGHT_UP)
			hold->x = floor((hold->h_y - 1) / SQR_SIZE);
		else
			hold->x = floor(hold->h_y / SQR_SIZE);
		if (check_wall(mlx, floor(hold->h_x / SQR_SIZE), hold->x))
			break ;
		hold->h_x += hold->xa;
		hold->h_y += hold->tile;
	}
}

void	get_sum_intersection_vertical(t_cub *mlx, t_info *hold)
{
	hold->v_y = intersection_v_ay(mlx, hold->side);
	hold->v_x = intersection_v_ax(mlx, hold->side);
	hold->v_tile = SQR_SIZE;
	if (hold->side == LEFT_UP || hold->side == LEFT_DOWN)
		hold->v_tile = -hold->v_tile;
	hold->v_ya = SQR_SIZE * tan(mlx->ray);
	if (hold->side == LEFT_UP || hold->side == RIGHT_UP)
		if (hold->v_ya > 0)
			hold->v_ya = -hold->v_ya;
	if (hold->side == LEFT_DOWN || hold->side == RIGHT_DOWN)
		if (hold->v_ya < 0)
			hold->v_ya = -hold->v_ya;
	while (1)
	{
		if (hold->side == RIGHT_UP || hold->side == RIGHT_DOWN)
			hold->z = floor(hold->v_x / SQR_SIZE);
		else
			hold->z = floor((hold->v_x - 1) / SQR_SIZE);
		if (check_wall(mlx, hold->z, floor(hold->v_y / SQR_SIZE)))
			break ;
		hold->v_x += hold->v_tile;
		hold->v_y += hold->v_ya;
	}
}

double	distance(t_cub *mlx, t_info *hold, bool x)
{
	if (x)
		return (sqrtl(pow(hold->v_x - mlx->x, 2) + pow(hold->v_y - mlx->y, 2)));
	else
		return (sqrtl(pow(hold->h_x - mlx->x, 2) + pow(hold->h_y - mlx->y, 2)));
}

void	check_text(double ray, t_cub *mlx)
{
	bool	down;
	bool	up;
	bool	left;
	bool	right;

	down = (ray > 0 && ray < M_PI);
	right = (ray < M_PI * 0.5 \
		|| ray > 1.5 * M_PI);
	up = !down;
	left = !right;
	if (left && mlx->verti)
		mlx->type = WEST;
	else if (right && mlx->verti)
		mlx->type = EAST;
	else if ((mlx->horiz) && up)
		mlx->type = NORTH;
	else if ((mlx->horiz) && down)
		mlx->type = SOUTH;
}

void	get_ray_angle(t_cub *mlx)
{
	int		x;
	t_info	*hold;
	double	ray_angle;

	x = 0;
	hold = malloc(sizeof(t_info));
	if (!hold)
		exit(1);
	mlx->ray = mlx->player_angle - (mlx->fov / 2);
	ray_angle = mlx->fov / mlx->ray_size;
	while (x < mlx->ray_size)
	{
		normilize_angle(mlx);
		hold->side = ray_side(mlx->ray);
		get_sum_intersection_horizontal(mlx, hold);
		get_sum_intersection_vertical(mlx, hold);
		distancegeter(mlx, hold, x);
		check_text(mlx->ray, mlx);
		mlx->ray += ray_angle;
		x++;
	}
	free(hold);
}
