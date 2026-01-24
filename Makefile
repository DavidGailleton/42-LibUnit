NAME			= libunit
CXX				= cc
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
CXXFLAGS	+= -g3
CXXFLAGS	+= -I $(LIBFT_DIR) -lft -Llibft
SRC				= util_unit.c
OBJ				= $(SRC:.cpp=.o)
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.c Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(SRC:.c=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

-include $(SRC:.c=.d)

.PHONY: all clean fclean re

