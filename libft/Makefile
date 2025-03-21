CC = gcc

HEADER = ./

LIBFT_SRCS = ft_printf/ft_putchar_fd_printf.c ft_printf/ft_putstr_fd_printf.c ft_printf/ft_putnbr_printf.c ft_printf/ft_putptr_fd_printf.c ft_printf/ft_unsigned_printf.c ft_printf/ft_to_hex_printf.c \
			ft_atoi.c

PRINTF_SRCS = ft_printf/ft_printf.c

SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS)

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wall -Wextra $(foreach dir, $(HEADER), -I$(dir))

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all