NAME = libft.a

SRC = \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_strlen.c \
ft_strchr.c \
ft_strncmp.c \
ft_strrchr.c \
ft_strlcpy.c \
ft_strnstr.c \
ft_toupper.c \
ft_tolower.c \
ft_bzero.c \
ft_memset.c \
ft_memcpy.c \
ft_memcmp.c \
ft_memchr.c \
ft_memmove.c \
ft_putstr_fd.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_calloc.c \
ft_strlcat.c \
ft_strdup.c \
ft_atoi.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_split.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -D
OBJ = $(SRC:.c=.o)
INCLUDES = -I. -I.

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
