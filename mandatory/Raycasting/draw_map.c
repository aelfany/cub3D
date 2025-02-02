/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:25:28 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/14 16:22:38 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_sky_ground(t_cub *mlx)
{
	int			x;
	int			y;
	uint32_t	clr;

	x = 0;
	clr = convetcolor(mlx->c);
	while (x < mlx->height)
	{
		y = 0;
		while (y < mlx->width)
		{
			mlx_put_pixel(mlx->img, y, x, clr);
			y++;
		}
		if (x == mlx->height / 2)
			clr = convetcolor(mlx->f);
		x++;
	}
}

void	draw_square(t_cub *cub, int x, int y, uint32_t clr)
{
	int	x_pos;
	int	y_pos;

	y_pos = 0;
	x_pos = 0;
	while (y_pos < SQR_SIZE)
	{
		x_pos = 0;
		while (x_pos < SQR_SIZE)
		{
			mlx_put_pixel(cub->img, x + x_pos, y + y_pos, clr);
			x_pos++;
		}
		y_pos++;
	}
}

void	draw_player(t_cub *mlx, double x_pos, double y_pos, int radius)
{
	double	x;
	double	y;

	x = x_pos - radius;
	while (x <= x_pos + radius)
	{
		y = y_pos - radius;
		while (y <= y_pos + radius)
		{
			if ((x - x_pos) * (x - x_pos) + (y - y_pos) * \
				(y - y_pos) <= radius * radius)
				mlx_put_pixel(mlx->img, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

void	buffer_img(t_cub *mlx, int width, int height, int y)
{
	int	n;

	n = 0;
	while (mlx->map[n])
	{
		y = 0;
		width = 0;
		while (mlx->map[n][y])
		{
			if (mlx->map[n][y] == 'N' || mlx->map[n][y] == 'W'
				|| mlx->map[n][y] == 'S' || mlx->map[n][y] == 'E')
				draw_square(mlx, width, height, 0xffffffff);
			if (mlx->map[n][y] == '0')
				draw_square(mlx, width, height, 0xffffffff);
			if (mlx->map[n][y] == '1')
				draw_square(mlx, width, height, 0x004DFF);
			width += SQR_SIZE;
			y++;
		}
		height += SQR_SIZE;
		n++;
	}
}

void	draw_map(t_cub *mlx, int x)
{
	if (x)
	{
		mlx_delete_image(mlx->ptr, mlx->img);
		mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	}
	draw_sky_ground(mlx);
	get_ray_angle(mlx);
	mlx_image_to_window(mlx->ptr, mlx->img, 0, 0);
}
