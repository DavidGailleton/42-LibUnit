NAME			= libunit
CXX				= cc
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
CXXFLAGS	+= -g3
CXXFLAGS	+= -I $(LIBFT_DIR)
LDFLAGS		= -Llibft -lft
SRC				= util_unit.c util_unit2.c
OBJ				= $(SRC:.cpp=.o)
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

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

