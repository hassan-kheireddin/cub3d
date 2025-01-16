
NAME = cub3D
CC = cc
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx_Linux.a
LIB = -L./minilibx-linux -L./libft -lft -lmlx_Linux -lXext -lX11 -lm
SRC_PATH = src/
OBJ_PATH = obj/
CFLAGS = -Wall -Werror -Wextra -g
DEBUG = -fsanitize=address
DEBUG_T = -fsanitize=thread
PERFORMANCE = -O3 -march=native -flto -funroll-loops
RM = rm -fr


FILES = main init \
		parse parse_utils parse_map set_player \
		calc_vector1  calc_dda \
		render_raycasting render_utils get_color \
		hooks \
		clean_exit

	

CUB3D_SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
CUB3D_OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
INCS = -I./includes 


DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)


$(NAME):			$(LIBFT) $(MLX) $(CUB3D_OBJ)
						@echo "$(YELLOW) Compiling: $@ $(DEF_COLOR)"
						@$(CC) $(INCS) $(CFLAGS) -O3 $(CUB3D_OBJ) $(LIB) -o $@

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
						@mkdir -p $(OBJ_PATH)
						@echo "$(YELLOW) Compiling: $< $(DEF_COLOR)"
						@$(CC) $(INCS) $(CFLAGS) -c $< -o $@

$(LIBFT):
						@make -C ./libft

$(MLX):
						@make -C ./minilibx-linux

clean:
						@$(RM) $(OBJ_PATH)
						@echo "$(BLUE)All objects files cleaned!$(DEF_COLOR)"

fclean: 			clean
						@$(RM) $(NAME)
						@make -C ./libft fclean
						@make -C ./minilibx-linux clean
						@echo "$(CYAN)All executable files cleaned!$(DEF_COLOR)"

re: 				fclean all
						@echo "$(GREEN)Cleaned and rebuilt everything$(DEF_COLOR)"

.PHONY: 			fclean all re clean
