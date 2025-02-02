/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:33:28 by abelfany          #+#    #+#             */
/*   Updated: 2023/12/15 21:50:02 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <libc.h>
# include <limits.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "src/get_next_line/get_next_line.h"

# define SQR_SIZE 32
# define LEFT_DOWN 180
# define LEFT_UP 270
# define RIGHT_DOWN 90
# define RIGHT_UP 360

typedef enum e_texture_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_texture_type;

typedef struct s_info
{
	int		tile;
	int		v_tile;
	double	x;
	double	z;
	double	xa;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	double	v_ya;
	double	side;
	double	intersection;
	double	raydistance;
}	t_info;

typedef struct s_gar
{
	char			**ptr;
	struct s_gar	*next;
}	t_gar;

typedef struct s_wall
{
	int		n;
	int		w;
	int		e;
	int		s;
	int		y;
	int		y0;
	int		y1;
	int		ray_e1;
	int		ray_e2;
	int		ray_w1;
	int		ray_w2;
	int		ray_s1;
	int		ray_s2;
	int		wstrip;
	int		walltop;
	int		walldown;
	double	wallheight;
	double	distancepro;
	double	intersection;
	int		distancefromtop;
}	t_wall;

typedef struct s_cub
{
	int				a;
	int				b;
	int				z;
	int				value;
	int				count;
	int				key_counter;
	int				delimiter;
	char			der;
	int				pos_y;
	int				pos_x;
	int				width;
	int				offsetx;
	int				offsety;
	unsigned int	color;
	int				height;
	unsigned int	pixels[100000000];
	int				half_height;
	int				half_width;
	double			x;
	double			y;
	mlx_texture_t	*tab[4];
	mlx_image_t		*img;
	mlx_image_t		*tex_img[4];
	mlx_texture_t	*tex;
	mlx_t			*ptr;
	bool			horiz;
	bool			verti;
	t_texture_type	type;
	/*--------player--------*/
	int				ray_size;
	double			ray;
	double			fov;
	double			ray_angle;
	double			player_angle;
	double			fr_ray_angle;
	double			routate_angle;
	/*----------------*/
	struct s_data	*content;
	char			**allmap;
	char			**map;
	char			**defmap;
	int				map_height;
	int				map_width;
	int				ones_length;
	int				der_x;
	int				der_y;
	char			*f;
	char			*c;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_cub;

/*		parsing		*/
void			loop(t_cub *mlx);
void			parse_rgb(t_cub *cub);
int				fun_check(char *str);
void			parse_xpmfiles(t_cub *cub);
void			checkmap(t_cub *cub);
void			parse_rgb(t_cub *cub);
void			parse_xpmfiles(t_cub *cub);
void			parse_map(t_cub *cub);
int				is_valid_surrounding(char c);
int				player_valid_surrounding(char c);
int				is_zero_valid(t_cub *cub, int i, int j);
int				player_valid(t_cub *cub, int i, int j);
void			parse_zeros(t_cub *cub);
void			parse_player(t_cub *cub);
char			*my_strstr(const char *haystack, const char *needle);
char			**ft_split2(char *s, char *c);
int				is_space(char c);
void			parse_empty_line(t_cub *cub);
void			checkmapextension(char *filename);
char			**read_map(t_cub *cub, char *av);
void			map_height(t_cub *cub, char *name);
void			ft_error(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
void			width_check(t_cub *cub);
char			*ft_substr(char const *s, unsigned int start, size_t len);
t_gar			*store_it(t_cub *cub);
char			**devide_map(t_cub *cub);
char			**defmap(t_cub *cub);
void			ones_length(t_cub *cub);
/*		raycasting		*/
void			get_ray_angle(t_cub *mlx);
int				filelen(void);
uint32_t		convetcolor(char *str);
int				maplen(char **str, int x);
double			distance(t_cub *mlx, t_info *hold, bool x);
int				check_wall(t_cub *mlx, int x, int y);
void			distancegeter(t_cub *mlx, t_info *hold, int x);
double			intersection_h_ax(t_cub *mlx, int side);
double			intersection_h_ay(t_cub *mlx, int side);
double			intersection_v_ax(t_cub *mlx, int side);
double			intersection_v_ay(t_cub *mlx, int side);
void			normilize_angle(t_cub *mlx);
int				ray_side(double ray_angle);
void			mlx_struct_init(t_cub *mlx);
void			draw_map(t_cub *cub, int x);
void			key_handler(void *param);
double			move_player(char der);
char			**ft_split(char const *s, char c);
void			free_string(char **ptr);
/*		textures		*/
void			init_textures(t_cub *cub);
void			delete_texture(t_cub *mlx);
void			free_gar(t_gar *gar);
int				get_rgba(int r, int g, int b, int a);
unsigned int	pixels_hexa(mlx_image_t *sight, unsigned int y, unsigned int x);
void			insert(t_gar **root, char **item);
void			*ft_calloc(size_t count, size_t size);
void			free_tools(t_cub *mlx, t_gar *gar);

#endif