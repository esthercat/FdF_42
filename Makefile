# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esmoreau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 19:16:47 by esmoreau          #+#    #+#              #
#    Updated: 2019/01/22 19:16:49 by esmoreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

.PHONY: all, $(NAME), clean, fclean, re

NAME = fdf

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
FRAMWK = -framework OpenGL -framework AppKit

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./OBJ/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fdf.h

SRC_NAME = main.c read.c error.c create_tab.c bresenham.c compteurs.c \
					keyboard.c rotation.c set_struct_data.c free.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RESET)$(CYAN)MAKING LIBFT ...$(RESET)"
	@make -C $(LFT_PATH)
	@echo "$(RESET)$(GREEN)LIBFTDONE\n$(RESET)"
	@echo "$(RESET)$(CYAN)MAKING MLX LIB ...$(RESET)"
	@make -C $(MLX_PATH)
	@echo "$(RESET)$(GREEN)MLX DONE\n$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L $(MLX_PATH) -lmlx -lm $(FRAMWK)
	@echo "$(RESET)$(GREEN)[✓] EXECUTABLE FDF DONE$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./includes/fdf.h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re-bis: clean_o $(NAME)

re: fclean all
