NAME			= libunit
CXX				= cc
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
CXXFLAGS	+= -g3
CXXFLAGS	+= -I $(LIBFT_DIR) -I.
LDFLAGS		= -Llibft -lft
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC				= libunit_util.c libunit_util2.c libunit.c main.c
SRC				+= real_tests/ft_strlen/00_launcher.c real_tests/ft_strlen/01_basic.c real_tests/ft_strlen/02_null.c
SRC				+= tests/libunit/00_launcher.c tests/libunit/01_ok.c tests/libunit/02_ko.c tests/libunit/03_sigsegv.c tests/libunit/04_sigbus.c
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

