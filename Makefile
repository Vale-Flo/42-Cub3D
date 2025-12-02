NAME		=	cub3D

CC			=	cc -g3
CFLAGS		=	-Wall -Werror -Wextra

LIB_DIR		=	libft/
MLX_DIR		=	minilibx-linux/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

LIBFT		=	$(LIB_DIR)libft.a
LMLX		=	$(MLX_DIR)libmlx.a

SRC_FILES	=	parsing/parsing.c \
				parsing/parse_text_col.c \
				parsing/parse_text_col_utils.c \
				parsing/parse_text_col_utils2.c \
				parsing/parse_map.c \
				parsing/parse_map_utils.c \
				utils/free_stuff.c \
				utils/init_stuff.c \
				utils/handle_errors.c \
				utils/debug_functions.c \
				utils/normalize_angle.c \
				render/draw.c \
				render/inputs.c \
				render/raycast.c \
				render/raycast2.c \
				render/textures.c \
				main.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

RED			= 	\033[1;31m
GREEN		= 	\033[1;32m
YELLOW		=	\033[1;33m
RESET		= 	\033[0m

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR)
	@echo "$(GREEN)$(LIBFT) compiled$(RESET)"

$(LMLX):
	@$(MAKE) -C $(MLX_DIR)
	@echo "$(GREEN)$(LMLX) compiled$(RESET)"

$(NAME): $(OBJ) $(LIBFT) $(LMLX)
#	@$(CC) $(CFLAGS) $^ -o $(NAME) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	@$(CC) $(CFLAGS) $^ -o $(NAME) -lXext -lX11 -lm
	@echo "$(GREEN)✅ $(NAME) compiled successfully$(RESET)"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "$(YELLOW)🧹 Cleaned objects$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@rm -f $(LMLX)
	@echo "$(RED)🗑️  Removed executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
