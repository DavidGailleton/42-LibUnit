NAME			= libunit.a
TNAME			= libunit
AR				= ar rcs
CXX				= cc
CXXFLAGS	= -Wall -Wextra -Werror -MMD -MP
CXXFLAGS	+= -g3
CXXFLAGS	+= -I$(LIBFT_DIR) -I. -Iframework
LDFLAGS		= -Llibft -lunit -lft -L.
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC				= framework/libunit_util.c framework/libunit_util2.c framework/libunit.c
TSRC			= main.c real_tests/ft_strlen/00_launcher.c real_tests/ft_strlen/01_basic.c real_tests/ft_strlen/02_null.c real_tests/ft_strlen/03_large.c
TSRC			+= tests/libunit/00_launcher.c tests/libunit/01_ok.c tests/libunit/02_ko.c tests/libunit/03_sigsegv.c tests/libunit/04_sigbus.c
OBJ				= $(SRC:.c=.o)
TOBJ			= $(TSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT_A)
	$(AR) $(NAME) $(OBJ)

$(TNAME): $(NAME) $(TOBJ) | $(LIBFT_A) $(NAME)
	$(CXX) $(CXXFLAGS) $(TOBJ) $(LDFLAGS) -o $(TNAME)

%.o: %.c Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ) $(TOBJ) $(SRC:.c=.d) $(TSRC:.c=.d)

fclean: clean
	$(RM) $(NAME) $(TNAME)

re: fclean
	$(MAKE) all

test: $(TNAME)
	./$(TNAME)

-include $(SRC:.c=.d) $(TSRC:.c=.d)

.PHONY: all clean fclean re

