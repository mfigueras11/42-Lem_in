NAME = lem-in
SRC = src/lemin.c src/solving.c src/checking.c src/parsing.c src/outputting.c src/solving2.c
OBJ = obj/lemin.o obj/solving.o obj/checking.o obj/parsing.o obj/outputting.o obj/solving2.o
INCL = -I incl/lemin.h
LIB = incl/libft/libft.a

all: $(NAME)

$(NAME):
	@mkdir obj
	@gcc -Wall -Werror -Wextra -c $(SRC) $(INCL)
	@mv lemin.o solving.o checking.o parsing.o outputting.o solving2.o ./obj/.
	@cd incl/libft && make re
	@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJ) $(LIB)

clean:
	@cd incl/libft && make clean
	@rm -rf obj

fclean: clean
	@cd incl/libft && make fclean
	@rm -f $(NAME)

re: fclean $(NAME)
