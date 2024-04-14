CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_cat_c.c ft_cat_s.c  ft_cat_p.c ft_cat_id.c ft_cat_u.c ft_cat_xX.c ft_cat_percent.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

LIBFTPATH = ./libft
LIBFT = ./libft/libft.a


all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ) 
	
$(OBJ):	$(SRC)
	$(CC)  $(CFLAGS) -c $(SRC)

$(LIBFT):
	make -C $(LIBFTPATH) bonus
	
clean:
	make -C $(LIBFTPATH) clean
	rm -f $(OBJ) $(OBJB)
	
fclean:	clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re:	fclean all
	
.PHONY: all fclean clean re libft
