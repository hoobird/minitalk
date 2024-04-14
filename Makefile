CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = server.c client.c
NAME = server client
FTPRINTF_PATH = ./ft_printf
FTPRINTF = $(FTPRINTF_PATH)/libftprintf.a
LIBFT = $(FTPRINTF_PATH)/libft/libft.a

all: $(NAME)

test:
	$(CC) $(CFLAGS) test.c $(FTPRINTF) $(LIBFT) -o test.o


$(NAME): $(SRCS) $(FTPRINTF)
	$(CC) $(CFLAGS) server.c $(FTPRINTF) $(LIBFT) -o server
	$(CC) $(CFLAGS) client.c $(FTPRINTF) $(LIBFT) -o client

$(FTPRINTF):
	make -C $(FTPRINTF_PATH) all


clean:
	rm -f $(OBJ)
	make -C $(FTPRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTPRINTF_PATH) fclean

re:	fclean all

phony: all fclean clean re libft ft_printf
