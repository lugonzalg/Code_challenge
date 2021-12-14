NAME	= Invictus

LIB		= -L $(PWD)/libft -lft
INC		= -I $(PWD)/libft/inc
CC		= clang
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3

FILES= main \

OBJS= $(addsuffix .o, $(FILES))
SRCS= $(addsuffix .c, $(FILES))

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

re: fclean all

clean:
	@${MAKE} -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@${MAKE} -C libft fclean
	$(RM) $(NAME)

.PHONY: all clean fclean re
