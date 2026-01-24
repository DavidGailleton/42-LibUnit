NAME			= libunit
CXX				= cc
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
CXXFLAGS	+= -g3
CXXFLAGS	+= -I $(LIBFT_DIR)
LDFLAGS		= -Llibft -lft
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC				= util_unit.c util_unit2.c launch_test.c
SRC				+= tests/main.c
SRC				+= tests/ft_strlen/00_launcher.c tests/ft_strlen/01_basic_test.c tests/ft_strlen/02_null_test.c
OBJ				= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT_A)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

-include $(SRC:.c=.d)

.PHONY: all clean fclean re

