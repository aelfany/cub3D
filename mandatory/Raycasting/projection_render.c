/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 01:00:08 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 21:39:18 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	top_half_wall(t_wall *ptr, t_cub *mlx, t_info *hold, int input_x)
{
	ptr->y1 = ((double)mlx->height / 2);
	ptr->y0 = ((double)mlx->height / 2) - ((double)ptr->wstrip / 2);
	mlx->offsetx = fmod(((hold->intersection * \
		mlx->tab[mlx->type]->width) / SQR_SIZE), mlx->tab[mlx->type]->width);
	ptr->y = ptr->y1;
	while (ptr->y > ptr->y0)
	{
		ptr->distancefromtop = ptr->y + (ptr->wstrip / 2) - (mlx->height / 2);
		mlx->offsety = ptr->distancefromtop * \
			((double)mlx->tab[mlx->type]->height / ptr->wstrip);
		mlx->color = pixels_hexa(mlx->tex_img[mlx->type], \
			mlx->offsety, mlx->offsetx);
		if (ptr->y >= 0 && ptr->y < mlx->height)
			mlx_put_pixel(mlx->img, input_x, ptr->y, mlx->color);
		else
			break ;
		ptr->y--;
	}
}

void	init_vars(t_wall *ptr, t_cub *mlx, t_info *hold)
{
	double	new_des;

	new_des = hold->raydistance * cos(mlx->ray - mlx->player_angle);
	ptr->distancepro = ((double)mlx->width / 2) / tan(mlx->fov / 2);
	ptr->wallheight = (SQR_SIZE / new_des) * ptr->distancepro;
	ptr->wstrip = (int)ptr->wallheight;
	ptr->y1 = ((double)mlx->height / 2);
	ptr->y0 = ((double)mlx->height / 2) + ((double)ptr->wstrip / 2);
	mlx->offsetx = fmod(((hold->intersection * \
		mlx->tab[mlx->type]->width) / SQR_SIZE), mlx->tab[mlx->type]->width);
	ptr->y = ptr->y1;
}

void	projection_walls(t_cub *mlx, t_info *hold, int input_x)
{
	t_wall	*ptr;

	ptr = malloc(sizeof(t_info));
	if (!ptr)
		exit(1);
	init_vars(ptr, mlx, hold);
	while (ptr->y < ptr->y0)
	{
		ptr->distancefromtop = ptr->y + (ptr->wstrip / 2) - (mlx->height / 2);
		mlx->offsety = ptr->distancefromtop * \
			((double)mlx->tab[mlx->type]->height / ptr->wstrip);
		mlx->color = pixels_hexa(mlx->tex_img[mlx->type], \
			mlx->offsety, mlx->offsetx);
		if (ptr->y >= 0 && ptr->y < mlx->height)
			mlx_put_pixel(mlx->img, input_x, ptr->y, mlx->color);
		else
			break ;
		ptr->y++;
	}
	top_half_wall(ptr, mlx, hold, input_x);
	free(ptr);
}

void	distancegeter(t_cub *mlx, t_info *hold, int x)
{
	if (distance(mlx, hold, 0) > distance(mlx, hold, 1))
	{
		hold->intersection = hold->v_y;
		mlx->verti = true;
		mlx->horiz = false;
		hold->raydistance = distance(mlx, hold, 1);
		projection_walls(mlx, hold, x);
	}
	else
	{
		mlx->horiz = true;
		mlx->verti = false;
		hold->intersection = hold->h_x;
		hold->raydistance = distance(mlx, hold, 0);
		projection_walls(mlx, hold, x);
	}
}
