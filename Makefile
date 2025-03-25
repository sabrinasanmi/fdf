# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 19:54:47 by sabsanto          #+#    #+#              #
#    Updated: 2025/03/25 17:49:08 by sabsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configurações Básicas
NAME		= fdf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

# Estrutura de Diretórios (personalize conforme necessário)
INC_DIR		= includes
SRC_DIR		= sources
OBJ_DIR		= objects
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux
PRINTF_DIR	= libft/ft_printf

# Fontes do Projeto (adicione todos os seus arquivos .c principais)
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Bibliotecas e Includes
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a
MLX			= $(MLX_DIR)/libmlx.a
INCLUDES	= -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)/include
LIBS		= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Cores para Output
GREEN		= \033[0;32m
BLUE		= \033[0;34m
RESET		= \033[0m

# Regras Principais
all: printf libft mlx $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)● Compiling: $(notdir $<)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Regras para Bibliotecas
libft:
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ libft compiled$(RESET)"

printf:
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)✓ ft_printf compiled$(RESET)"

mlx:
	@make -C $(MLX_DIR)
	@echo "$(GREEN)✓ minilibx compiled$(RESET)"

# Limpeza
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)✓ Objects cleaned$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Full clean completed$(RESET)"

re: fclean all

.PHONY: all clean fclean re libft mlx