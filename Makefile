NAME = fillit
OBJS = objs/main.o objs/validation.o \
	objs/piece_creation.o objs/solver.o
HEADERS = fillit.h libft/libft.h
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS): objs/%.o: srcs/%.c $(HEADERS) objs
	gcc $(CFLAGS) -c $< -o $@

objs:
	mkdir objs

$(LIBFT):
	make -C libft

clean:
	rm -rf objs
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re