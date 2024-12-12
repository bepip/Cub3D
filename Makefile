NAME	=	Cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I./includes \
	  -I./mlx \
	  -I.

#LIBFT
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/

SRC_FILES =	main.c \
			init/file_utils.c \
			init/check_file.c \
			init/check_texture.c \
			init/init_map.c \
			init/init_raycast.c \
			init/init_map_utils.c \
			init/init_game.c \
			init/init_game_utils.c \
			init/init_mlx.c \
			init/init_blank_game.c \
			init/init_dir.c \
			init/check_map.c \
			utils/display.c \
			utils/error.c \
			utils/free.c \
			render/raycasting.c \
			render/mlx_draw_vertline.c \
			events/close_window.c \
			events/movement_keys.c \
			events/rotation_keys.c \

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

#BONUS
BNAME = Cub3D_bonus
BSRC_DIR = ./srcs_bonus/
BOBJ_DIR = ./objs_bonus/

BSRC_FILES =	main_bonus.c \
			init/file_utils_bonus.c \
			init/check_file_bonus.c \
			init/check_texture_bonus.c \
			init/init_map_bonus.c \
			init/init_raycast_bonus.c \
			init/init_map_utils_bonus.c \
			init/init_game_bonus.c \
			init/init_game_utils_bonus.c \
			init/init_mlx_bonus.c \
			init/init_blank_game_bonus.c \
			init/init_dir_bonus.c \
			init/check_map_bonus.c \
			utils/display_bonus.c \
			utils/error_bonus.c \
			utils/free_bonus.c \
			render/raycasting_bonus.c \
			render/mlx_draw_vertline_bonus.c \
			render/render_bonus.c \
			render/startscreen_bonus.c \
			render/animation_bonus.c \
			events/keypress_handle_bonus.c \
			events/keyrelease_handle_bonus.c \
			events/player_actions_bonus.c \
			events/player_actions_utils_bonus.c \
			events/keys_utils_bonus.c \
			events/mouse_handle_bonus.c \
			events/close_window_bonus.c \
			events/movement_keys_bonus.c \
			events/rotation_keys_bonus.c \
			minimap/minimap_bonus.c \

BSRCS = $(addprefix $(BSRC_DIR), $(BSRC_FILES))

BOBJS = $(addprefix $(BOBJ_DIR), $(BSRC_FILES:.c=.o))

#MLX
# je sais pas pq le flag -lmlx_Linux compile pas check si tu as ces flags
# I don't know why the flag -lmlx_Linux doesn't compile. help
MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lz
#MLX_FLAGS	= -Lmlx -lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
MLX_PATH	=	./mlx
MLX 		=	$(MLX_PATH)/libmlx.a

# Colors
YELLOW = \033[1;33m
GREEN = \033[1;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)init
	mkdir -p $(OBJ_DIR)utils
	mkdir -p $(OBJ_DIR)render
	mkdir -p $(OBJ_DIR)events

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(MLX) $(LIBFT) $(BOBJ_DIR) $(BOBJS)
	$(CC) $(CFLAGS) $(INC) $(BOBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(BNAME)
	@echo "$(GREEN) $(BNAME) compiled successfully!$(RESET)"

$(BOBJ_DIR):
	mkdir -p $(BOBJ_DIR)
	mkdir -p $(BOBJ_DIR)init
	mkdir -p $(BOBJ_DIR)utils
	mkdir -p $(BOBJ_DIR)render
	mkdir -p $(BOBJ_DIR)events
	mkdir -p $(BOBJ_DIR)minimap

$(BOBJ_DIR)%.o: $(BSRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(BOBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f $(NAME)
	rm -f $(BNAME)

re: fclean all

rbonus: fclean bonus

.PHONY: all clean fclean re rbonus
