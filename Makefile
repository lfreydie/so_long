# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:01:41 by lfreydie          #+#    #+#              #
#    Updated: 2023/04/04 13:31:34 by lfreydie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- Project ---------- #

CC ?= gcc
NAME := so_long
NAME_B := so_long_bonus
CFLAGS += -Wall -Wextra -Werror -g
LIB_FLAGS = -L -lmlx -lXext -lX11

# -------- Directories -------- #

HD_DIR = ./includes
SRC_DIR = ./src
BONUS_DIR = ./bonus
OBJ_DIR = ./objs
OBJ_B_DIR = ./objs_b
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx

# ---------- Delete ----------- #

RM = rm -f
RM_OPT = -r

# ---------- Library ---------- #

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# ---------- Colors ----------- #

GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
PINK=\033[0;35m
END=\033[0m

# ----------- Files ----------- #

SRC = $(shell find $(SRC_DIR) -type f -name *.c)
OBJ = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.c=.o))

SRC_B = $(shell find $(BONUS_DIR) -type f -name *.c)
OBJ_B = $(patsubst $(BONUS_DIR)/%,$(OBJ_B_DIR)/%,$(SRC_B:.c=.o))

# --------- Compiles ---------- #

$(NAME) :	$(LIBFT) $(OBJ)
	@echo "$(BLUE) ==== Project compiling ==== $(END)"
	@$(CC) $(CFLAGS) -I $(HD_DIR) $(OBJ) $(LIBFT) $(MLX) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREEN) ==== Project compiled ==== $(END)"

$(LIBFT) :
	@echo "$(BLUE) ==== libft compiling ==== $(END)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN) ==== libft compiled ==== $(END)"

# ----------- Link ------------ #

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(HD_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_B_DIR)/%.o : $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(HD_DIR) -I $(LIBFT_DIR) -c $< -o $@

# ----------- Rules ----------- #

all :	$(NAME)

bonus :	$(OBJ_B)
	@$(CC) $(CFLAGS) -I $(HD_DIR) $(OBJ_B) $(LIBFT) $(MLX) $(LIB_FLAGS) -o $(NAME_B)
	@echo "$(GREEN) ==== Bonus compiled ==== $(END)"

clean :
	@$(RM) $(RM_OPT) $(OBJ_DIR) $(OBJ_B_DIR)
	@make clean -sC $(LIBFT_DIR)
	@echo "$(PINK) ==== All object removed ==== $(END)"

fclean :	clean
	@$(RM) $(NAME) $(NAME_B)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(RED) ==== Executables removed ==== $(END)"

scan :
	@echo "	$(BLUE) ==== Scan running ==== $(END)"
	@scan-build-12 make -s
	@echo "	$(GREEN) ==== Scan finished ==== $(END)"

re :	fclean all

.PHONY : all clean fclean scan re
