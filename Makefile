NAME = push_swap

CC = gcc
FLAG = -Wall -Wextra -Werror
HEADER = push_swap.h

OBJ_DIR = obj
SRC_DIR = src
PRINTF_DIR = ft_printf
LIBFT_DIR = libft

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(PRINTF) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -g -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
