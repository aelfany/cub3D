/* ************************************************************************** */
/*									                                        */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:30:07 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/10 11:01:55 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	filelen(void)
{
	int		fd;
	char	*str;
	int		n;

	str = NULL;
	n = 0;
	fd = open("map.cub", O_CREAT | O_RDONLY);
	while (get_next_line(fd) != NULL)
		n++;
	return (n);
}

int	get_player_pos(char **str, double *y, char *c)
{
	int	a;
	int	b;

	a = 0;
	while (str[a])
	{
		b = 0;
		while (str[a][b])
		{
			if (str[a][b] == 'N' || str[a][b] == 'E'
				|| str[a][b] == 'W' || str[a][b] == 'S')
			{
				(*c) = str[a][b];
				return ((*y) = b * SQR_SIZE + (SQR_SIZE / 2),
					a * SQR_SIZE + (SQR_SIZE / 2));
			}
			b++;
		}
		a++;
	}
	return (0);
}

t_gar	*parse_elements(t_cub *cub)
{
	checkmap(cub);
	parse_rgb(cub);
	parse_xpmfiles(cub);
	return (store_it(cub));
}

void	map_parse(t_cub *cub)
{
	parse_empty_line(cub);
	parse_map(cub);
	parse_zeros(cub);
	parse_player(cub);
}

int	main(int ac, char **av)
{
	t_cub	*mlx;
	t_gar	*gar;

	if (ac != 2)
		ft_error("Invalid arguments");
	mlx = malloc(sizeof(t_cub));
	if (!mlx)
		exit(1);
	checkmapextension(av[1]);
	mlx_struct_init(mlx);
	map_height(mlx, av[1]);
	mlx->allmap = read_map(mlx, av[1]);
	gar = parse_elements(mlx);
	mlx->map = devide_map(mlx);
	ones_length(mlx);
	width_check(mlx);
	mlx->defmap = defmap(mlx);
	map_parse(mlx);
	mlx->y = get_player_pos(mlx->map, &mlx->x, &mlx->der);
	mlx->player_angle = move_player(mlx->der);
	mlx->ptr = mlx_init(mlx->width, mlx->height, "cub3D", 1);
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	init_textures(mlx);
	loop(mlx);
	free_tools(mlx, gar);
}
