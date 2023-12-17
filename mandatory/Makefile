# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 17:37:55 by abelfany          #+#    #+#              #
#    Updated: 2023/12/15 21:44:06 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = cub3D.h
NAME = cub3D
GPT = src/get_next_line/
SRC_M = Raycasting/main.c $(GPT)get_next_line.c $(GPT)get_next_line_utils.c Raycasting/raycasting.c parse/check_duplicates.c parse/fencing_check.c \
	parse/check_elemnts.c parse/read_file.c parse/read_map.c parse/ft_error.c parse/parse_utils.c Raycasting/get_intersection_hv.c Raycasting/tools.c Raycasting/struct_tools.c \
	Raycasting/draw_map.c Raycasting/hook.c Raycasting/ft_split.c Raycasting/draw_helper.c \
	Raycasting/projection_render.c rendering/textures_loading.c parse/check_xpm.c clean_mlx.c

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
