# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 19:54:47 by sabsanto          #+#    #+#              #
#    Updated: 2025/04/28 20:12:29 by sabsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

SRC_LIB = $(addprefix  src/libft/, ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
          ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c ft_bzero.c ft_calloc.c ft_memchr.c \
          ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
          ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
          ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
          ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c)
OBJ_LIB = $(addprefix $(OBJDIR_LIBFT), $(notdir $(SRC_LIB:.c=.o)))

SRC_PRINTF = $(addprefix  src/ft_printf/, ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunbr.c ft_putuphex.c)
OBJ_PRINTF = $(addprefix $(OBJDIR_PRF), $(notdir $(SRC_PRINTF:.c=.o)))

SRC_GNL = $(addprefix  src/gnl/, get_next_line.c get_next_line_utils.c)
OBJ_GNL = $(addprefix $(OBJDIR_GNL), $(notdir $(SRC_GNL:.c=.o)))

SRC = $(addprefix src/, $(SRC_LIB) $(SRC_GNL) $(SRC_PRINTF))

OBJ = $(OBJ_GNL) $(OBJ_LIB) $(OBJ_PRINTF)

OBJDIR_GNL = obj/gnl/
OBJDIR_LIBFT = obj/libft/
OBJDIR_PRF = obj/ft_printf/

FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	ar rus $(NAME) $(OBJ)

$(OBJ): $(OBJDIR_GNL) $(OBJDIR_LIBFT) $(OBJDIR_PRF)

$(OBJDIR_GNL):
	mkdir -p $(OBJDIR_GNL)

$(OBJDIR_PRF):
	mkdir -p $(OBJDIR_PRF)

$(OBJDIR_LIBFT):
	mkdir -p $(OBJDIR_LIBFT)

$(OBJDIR_PRF)%.o: src/ft_printf/%.c 
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

$(OBJDIR_GNL)%.o: src/gnl/%.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

$(OBJDIR_LIBFT)%.o: src/libft/%.c
	$(CC) $(FLAGS) -c -o $@ $< -I includes/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all