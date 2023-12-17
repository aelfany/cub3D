/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:33:41 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 14:14:35 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tools(t_cub *mlx, t_gar *gar)
{
	free_string(mlx->allmap);
	free_string(mlx->defmap);
	free_gar(gar);
	delete_texture(mlx);
}

void	free_gar(t_gar *gar)
{
	t_gar	*tmp;

	while (gar)
	{
		tmp = gar;
		free_string(gar->ptr);
		gar = gar -> next;
		free(tmp);
	}
}

void	delete_texture(t_cub *mlx)
{
	mlx_delete_image(mlx->ptr, mlx->img);
	mlx_delete_image(mlx->ptr, mlx->tex_img[NORTH]);
	mlx_delete_image(mlx->ptr, mlx->tex_img[SOUTH]);
	mlx_delete_image(mlx->ptr, mlx->tex_img[EAST]);
	mlx_delete_image(mlx->ptr, mlx->tex_img[WEST]);
	mlx_delete_texture(mlx->tab[NORTH]);
	mlx_delete_texture(mlx->tab[SOUTH]);
	mlx_delete_texture(mlx->tab[EAST]);
	mlx_delete_texture(mlx->tab[WEST]);
	free(mlx);
}
