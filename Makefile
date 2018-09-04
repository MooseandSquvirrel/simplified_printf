NAME = printf

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  super_simple_parser.c \
	  super_simple_printf.c \
	  if_s.c \
	  if_c.c \
	  if_di.c \
	  if_o.c \
	  if_p.c \
	  if_x.c \
	  if_u.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

$(NAME): $(LIBFT) $(OBJ)
	gcc $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	@make -C libft/

clean:
	@echo "Cleaning!"
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@echo "Fcleaning!"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
