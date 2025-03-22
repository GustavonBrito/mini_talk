CC = gcc

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a

HEADER = -I $(LIBFT_DIR)

NAME = client server

SRCS = client.c server.c

OBJS = client server

CFLAGS = -Werror -Wall -Wextra

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

client: $(LIBFT)
	$(CC) $(CFLAGS) client.c -o client $(LIBFT)

server: $(LIBFT)
	$(CC) $(CFLAGS) server.c -o server $(LIBFT)

clean:
	@make -C $(LIBFT_DIR) clean

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re