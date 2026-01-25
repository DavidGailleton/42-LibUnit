NAME			= libunit.a
AR				= ar rcs
CC				= cc
CCFLAGS		= -Wall -Wextra -Werror -MMD -MP
CCFLAGS		+= -I$(LIBFT_DIR) -I. -Iframework
LDFLAGS		= -Llibft -lunit -lft -L.
LIBFT_DIR = libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC				= framework/libunit_util.c framework/libunit_util2.c framework/libunit.c
OBJ				= $(SRC:.c=.o)

TESTD			= tests
TESTB			= $(TESTD)/tests
TESTM			= $(TESTD)/Makefile
RTESTD		= real_tests
RTESTB		= $(RTESTD)/real_tests
RTESTM		= $(RTESTD)/Makefile

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT_A)
	$(AR) $(NAME) $(OBJ)

%.o: %.c Makefile
	$(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT_A): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJ) $(SRC:.c=.d)
	@$(MAKE) -C $(TESTD) clean
	@$(MAKE) -C $(RTESTD) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(TESTD) fclean
	@$(MAKE) -C $(RTESTD) fclean

re: fclean
	@$(MAKE) all

$(TESTB): FORCE
	@$(MAKE) -C $(TESTD)

$(RTESTB): FORCE
	@$(MAKE) -C $(RTESTD)

test: $(TESTB) $(RTESTB)
	$(TESTB)
	$(RTESTB)

FORCE: ;

-include $(SRC:.c=.d)

.PHONY: all clean fclean re

