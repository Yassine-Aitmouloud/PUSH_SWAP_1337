NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
CFILES = utils.c 


OBJM = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJM)
	$(CC) $(CFLAGS) $(CFILES) -o $(NAME)

clean:
	rm -f $(OBJM) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
