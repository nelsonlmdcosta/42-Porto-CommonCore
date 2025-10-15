NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Mandatory source files
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Optional: list files for bonus (assuming named ft_lst*.c)
BONUS_SRC = $(wildcard ft_lst*.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

# Build library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compile individual object files
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Remove objects and library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Bonus target: compile bonus list functions into library
bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)
