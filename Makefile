NAME = push_swap

SRCS = main.c utils.c utils_sort.c radix_sort.c bubble.c push_swap.c push_swap_tow.c  libft/libft.a 

OBJECTS = $(SRCS:%.c=%.o)
HEADER = push_swap.h

LIBFT_DIR = libft
LIBFT_REPO = https://github.com/Lumelig/libft.git

LIBFT = $(LIBFT_DIR)/libft.a
LIB_DIRS = -L$(LIBFT_DIR)
INCLUDES = -I$(LIBFT_DIR)/libft

CC = cc 
#CFLAGS = -Wall -Werror -Wextra

all: libft $(NAME)

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(LIB_DIRS) $(INCLUDES)

clean:
	rm -fr $(OBJECTS)
	

fclean:
	rm -fr push_swap
	rm -fr $(OBJECTS)
	@make -C $(LIBFT_DIR) fclean
	rm -fr $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft