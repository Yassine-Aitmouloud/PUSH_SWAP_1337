NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
CFILES = utils.c main.c utils2.c  utils3.c utils4.c utils5.c utils6.c utils7.c utils8.c utils9.c utils10.c


OBJM = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJM) push_swap.h
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:
	rm -f $(OBJM) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re