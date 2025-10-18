NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./libft
AR = ar rcs
RM = rm -f

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Sources
SRC = $(shell find . -name "*.c" ! -path "./libft/*")
OBJ = $(SRC:.c=.o)

# ------------------------------ Rules ------------------------------ #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(AR) rcs $(NAME) $(OBJ) $(LIBFT)
	@echo "$(NAME) built successfully"

# Compile libft first
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
