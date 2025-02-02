/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:24:14 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 16:18:26 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	mlx_struct_init(t_cub *mlx)
{
	mlx->map = NULL;
	mlx->img = NULL;
	mlx->ptr = NULL;
	mlx->a = 0;
	mlx->b = 0;
	mlx->value = 0;
	mlx->count = 0;
	mlx->key_counter = 0;
	mlx->fov = M_PI / 3;
	mlx->width = 1000;
	mlx->height = 1000;
	mlx->half_height = mlx->height / 2;
	mlx->allmap = NULL;
	mlx->map = NULL;
	mlx->half_width = mlx->width / 2;
	mlx->ray_size = mlx->width;
	mlx->routate_angle = 1;
	mlx->ray_angle = (mlx->player_angle - (mlx->fov / 2)) / mlx->ray_size;
}
