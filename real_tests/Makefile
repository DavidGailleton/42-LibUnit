NAME    	= real_tests
CC				= cc
CCFLAGS		= -Wall -Wextra -Werror -MMD -MP

SRC     	= main.c
SRC				+= ft_strlen/00_launcher.c ft_strlen/01_basic.c ft_strlen/02_null.c ft_strlen/03_large.c
SRC				+= ft_atoi/00_launcher.c ft_atoi/01_basic.c ft_atoi/02_int_max.c ft_atoi/03_int_min.c ft_atoi/04_null.c
SRC				+= ft_strncmp/00_launcher.c ft_strncmp/01_basic.c ft_strncmp/02_len.c ft_strncmp/03_high_len.c
SRC				+= ft_strdup/00_launcher.c ft_strdup/01_basic.c ft_strdup/02_null.c
SRC				+= ft_itoa/00_launcher.c ft_itoa/01_positif.c ft_itoa/02_negatif.c ft_itoa/03_zero.c ft_itoa/04_int_max.c ft_itoa/05_int_min.c
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
	@$(MAKE) -C ..

clean:
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(SRC:.c=.d)

.PHONY: all clean fclean re libunit
