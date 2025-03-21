# CC = gcc

# LIBFT_DIR = libft

# LIBFT = $(LIBFT_DIR)/libft.a

# HEADER = -I $(LIBFT_DIR/headers)

# NAME = client server

# SRCS = client.c	server.c

# OBJS = client server

# CFLAGS = -Werror -Wall -Wextra -I $(HEADER)

# all: $(LIBFT) $(NAME)

# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# client: $(LIBFT)
# 	$(CC) $(CFLAGS) $(HEADER) client.c -o client -L	$(LIBFT_DIR) -lft

# server: $(LIBFT)
# 	$(CC) $(CFLAGS) $(HEADER) server.c -o server -L	$(LIBFT_DIR) -lft

# clean:
# 	@make -C $(LIBFT_DIR) clean
# 	rm -f $(OBJS)

# fclean:
# 	@make -C $(LIBFT_DIR) fclean
# 	rm -f $(OBJS) $(NAME)

# re:
# 	@$(MAKE) fclean
# 	@$(MAKE) all

# .PHONY: all clean fclean re

CC = gcc

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a  # Alterado para usar libftprintf.a

HEADER = -I $(LIBFT_DIR)

NAME = client server

SRCS = client.c server.c

OBJS = client server

CFLAGS = -Werror -Wall -Wextra

start:
	@make -C $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

client: $(LIBFT)
	$(CC) $(CFLAGS) client.c -o client $(LIBFT)

server: $(LIBFT)
	$(CC) $(CFLAGS) server.c -o server $(LIBFT)

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re