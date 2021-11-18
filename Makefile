# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 10:31:00 by cbignon           #+#    #+#              #
#    Updated: 2021/10/28 10:45:23 by cbignon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OSTYPE = $(shell uname)

SRCS = $(wildcard src/*.c src/*/*.c)
OBJS = $(SRCS:.c=.o)

CC = clang
FLAGS = -Wall -Wextra -g3
# -g3 -fsanitize=address
# -Werror

LIBFT_PATH = lib/libft/
LIBFT = $(LIBFT_PATH)libft.a
LIBS = $(LIBFT) -lm -Imlx

HEADERS = -I srcs/ -I mlx -I $(LIBFT_PATH) -I.

ifeq ($(OSTYPE),Linux)
	MLX_PATH = lib/mlx_linux/
	MLX = $(MLX_PATH)libmlx.a
	LIBS += $(MLX) -L $(MLX_PATH) -lXext -lX11
	HEADERS += -I lib/mlx_linux
	FLAGS += -DLINUX -O3
else
	MLX_PATH = lib/mlx/
	MLX = $(MLX_PATH)libmlx.a
	LIBS += $(MLX) -framework OpenGL -framework AppKit
	HEADERS += -I $(MLX_PATH)
endif

all: $(NAME)
	@echo "so_long is ready!"

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@echo "Source files compiling..."
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "Source files compiled"

.c.o:
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

$(MLX):
	@echo "Compiling MiniLibX for $(OSTYPE)..."
	@make -s -C $(MLX_PATH)
	@echo "MiniLibX for $(OSTYPE) compiled !"

$(LIBFT):
	@echo "Compiling Libft..."
	$(MAKE) -C $(LIBFT_PATH) -f Makefile
	@echo "Libft compiled"

clean_libft:
	$(MAKE) -C $(LIBFT_PATH) -f Makefile clean

clean_mlx:
	$(MAKE) -C $(MLX_PATH) -f Makefile clean

fclean_mlx: clean_mlx
	@rm -f $(MLX)

clean_objs:
	@rm -rf $(OBJS)

clean: clean_mlx clean_libft clean_objs

fclean_exec: clean_objs
	@rm -rf $(NAME)

fclean_libft:
	@$(MAKE) -C $(LIBFT_PATH) -f Makefile fclean

fclean: fclean_mlx fclean_libft fclean_exec
	@echo "Evrything is clean"

re_nolib: fclean_exec newline all

re: fclean all clean_objs

# For object files, you could add the following rule to your makefile, assuming that you have the mlx for linux source in a directory named mlx_linux in the root of your project:

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
# To link with the required internal Linux API:

# $(NAME): $(OBJ)
# 	$(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


# For object files, you could add the following rule to your makefile, assuming that you have the mlx source in a directory named mlx in the root of your project:

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# To link with the required internal macOS API:

# $(NAME): $(OBJ)
# 	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)