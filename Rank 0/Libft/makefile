# Basics Setup
NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Find All Our Files And Place Them In Buckets
ALL_SRC = $(wildcard ft_*.c)
SRC     = $(filter-out ft_lst%.c, $(ALL_SRC))
BONUS   = $(filter ft_lst%.c, $(ALL_SRC))

# Rules To Output To
OBJ     = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# Just Do It All!
all: $(NAME)

# Archives the mandatory objects only
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Archives the bonues objects only
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Compiles into intermediate objects the c filess
# $< expands the file name, aka my main.c
# $@ expands the file name, aka my main.o as an example
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Removes All Objects Files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Cleans everything out
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# We use .PHONY for targets so they dont correspond to files.
.PHONY: all bonus clean fclean re
