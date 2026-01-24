NAME    	= tests
CC				= cc
CCFLAGS		= -Wall -Wextra -Werror -MMD -MP

SRC     	= main.c
SRC				+= libunit/00_launcher.c libunit/01_ok.c libunit/02_ko.c libunit/03_sigsegv.c libunit/04_sigbus.c
OBJ     	= $(SRC:.c=.o)

LIBS    	= -L.. -lunit -L../libft -lft
INC     	= -I. -I../framework -I../libft

all: $(NAME)

test: $(NAME)
	./$(NAME)

%.o: %.c Makefile
	$(CC) $(CCFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ) | libunit
	$(CC) $(CCFLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)

libunit:
	$(MAKE) -C ..

clean:
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(SRC:.c=.d)

.PHONY: all clean fclean re libunit
