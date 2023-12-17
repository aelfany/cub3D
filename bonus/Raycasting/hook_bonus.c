/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:29:39 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 21:50:38 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

void	loop(t_cub *mlx)
{
	draw_map(mlx, 0);
	mlx_loop_hook(mlx->ptr, key_handler, mlx);
	mlx_loop(mlx->ptr);
}

void	handler_helper(t_cub *mlx, int *flag)
{
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_S))
	{
		mlx->x -= cos(mlx->player_angle);
		mlx->y -= sin(mlx->player_angle);
		(*flag) = 1;
	}
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_W))
	{
		mlx->x += cos(mlx->player_angle);
		mlx->y += sin(mlx->player_angle);
		(*flag) = 1;
	}
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_A))
	{
		mlx->x += cos(mlx->player_angle - M_PI_2);
		mlx->y += sin(mlx->player_angle - M_PI_2);
		(*flag) = 1;
	}
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_D))
	{
		mlx->x -= cos(mlx->player_angle - M_PI_2);
		mlx->y -= sin(mlx->player_angle - M_PI_2);
		(*flag) = 1;
	}
}

void	mlx_mouse(t_cub *mlx, int *flag)
{
	static int	prv_x;
	int			x;
	int			y;

	mlx_get_mouse_pos(mlx->ptr, &x, &y);
	if (prv_x != x)
	{
		mlx->player_angle = (double)x / 90;
		(*flag) = 1;
	}
	mlx_set_cursor_mode(mlx->ptr, MLX_MOUSE_DISABLED);
	prv_x = x;
}

void	key_handler(void *param)
{
	t_cub		*mlx;
	int			flag;

	mlx = (struct s_cub *)param;
	flag = 0;
	mlx_mouse(mlx, &flag);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->ptr);
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_RIGHT))
	{
		mlx->player_angle += 0.02;
		if (mlx->player_angle > (M_PI * 2))
			mlx->player_angle -= M_PI * 2;
		flag = 1;
	}
	if (mlx_is_key_down(mlx->ptr, MLX_KEY_LEFT))
	{
		mlx->player_angle -= 0.02;
		if (mlx->player_angle < 0)
			mlx->player_angle += M_PI * 2;
		flag = 1;
	}
	handler_helper(mlx, &flag);
	if (flag == 1)
		draw_map(mlx, 1);
}
