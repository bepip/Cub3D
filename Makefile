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
			init/init_game.c \
			init/file_utils.c \
			init/check_file.c \
			init/init_map.c \
			init/check_map.c \
			utils/display.c \
			utils/error.c \
			utils/free.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

#MLX
# je sais pas pq le flag -lmlx_Linux compile pas check si tu as ces flags
# I don't know why the flag -lmlx_Linux doesn't compile. help
#MLX_FLAGS = -Lmlx -lmlx -lXext -lX11 -lm -lz
MLX_FLAGS	= -Lmlx -lmlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
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
	mkdir -p $(OBJ_DIR)actions

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_PATH)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
