/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_loading_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:17:38 by otchekai          #+#    #+#             */
/*   Updated: 2023/12/15 19:21:43 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	load_textures(char *path, t_cub *cub, t_texture_type type)
{
	if (type == NORTH)
	{
		cub->tab[NORTH] = mlx_load_png(path);
		if (cub->tab[NORTH] == NULL)
			return (0);
	}
	if (type == SOUTH)
	{
		cub->tab[SOUTH] = mlx_load_png(path);
		if (cub->tab[SOUTH] == NULL)
			return (0);
	}
	if (type == WEST)
	{
		cub->tab[WEST] = mlx_load_png(path);
		if (cub->tab[WEST] == NULL)
			return (0);
	}
	if (type == EAST)
	{
		cub->tab[EAST] = mlx_load_png(path);
		if (cub->tab[EAST] == NULL)
			return (0);
	}
	return (1);
}

void	init_textures(t_cub *cub)
{
	if (!load_textures(cub->so, cub, SOUTH))
		ft_error("South texture couldn't load");
	if (!load_textures(cub->ea, cub, EAST))
		ft_error("East texture couldn't load");
	if (!load_textures(cub->we, cub, WEST))
		ft_error("West texture couldn't load");
	if (!load_textures(cub->no, cub, NORTH))
		ft_error("North texture couldn't load");
	cub->tex_img[NORTH] = mlx_texture_to_image(cub->ptr, cub->tab[NORTH]);
	cub->tex_img[SOUTH] = mlx_texture_to_image(cub->ptr, cub->tab[SOUTH]);
	cub->tex_img[EAST] = mlx_texture_to_image(cub->ptr, cub->tab[EAST]);
	cub->tex_img[WEST] = mlx_texture_to_image(cub->ptr, cub->tab[WEST]);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	pixels_hexa(mlx_image_t *sight, unsigned int y, unsigned int x)
{
	uint8_t		*colors;

	if (sight == NULL || y >= sight->height
		|| x >= sight->width)
		return (0);
	colors = &sight->pixels[(y * (sight->width * 4) + x * 4)];
	return (get_rgba(colors[0], colors[1], colors[2], 255));
}
