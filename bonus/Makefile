# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 17:37:55 by abelfany          #+#    #+#              #
#    Updated: 2023/12/15 21:43:52 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = cub3D_bonus.h
NAME = cub3D_bonus
GPT = src/get_next_line/
SRC_M = Raycasting/ft_split_bonus.c Raycasting/projection_render_bonus.c Raycasting/get_intersection_hv_bonus.c \
		Raycasting/raycasting_bonus.c Raycasting/draw_helper_bonus.c Raycasting/hook_bonus.c Raycasting/struct_tools_bonus.c \
		Raycasting/draw_map_bonus.c Raycasting/main_bonus.c Raycasting/tools_bonus.c \
		parse/check_xpm_bonus.c parse/read_file_bonus.c parse/fencing_check_bonus.c parse/read_map_bonus.c \
		parse/check_duplicates_bonus.c parse/ft_error_bonus.c parse/check_elemnts_bonus.c parse/parse_utils_bonus.c \
		rendering/textures_loading_bonus.c clean_mlx_bonus.c $(GPT)get_next_line.c $(GPT)get_next_line_utils.c

OBJ_S = $(SRC_M:.c=.o)
CFLAG = -Wall -Wextra -Werror -Ofast -I MLX42/include
CC = cc
RM = -@rm -rf
MLX = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
MLXLIB = "../MLX42/build/libmlx42.a"
all : $(NAME) 
	@echo "                      \033[0;106m\033[\033[0;33m🄱 🅈 \033[0;106m 🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
	@echo "                      \033[0;106m\033[\033[0;33m🄱 🅈 \033[0;106m 🄰 🄱_🄴 🄻 🄵 🄰 🄽 🅈 \033[0;33m"
%.o: %.c $(HEADER) Makefile
	cc -Wall -Wextra -Werror -c $< -I $(HEADER) -o $@

$(NAME): $(OBJ_S)
	cc $(CFLAG) $(OBJ_S) $(MLX) $(MLXLIB) -o $(NAME)

bonus: fclean all

clean:
	$(RM) $(OBJ_S)

fclean:clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
