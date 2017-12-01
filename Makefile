# Compiler configuration
CCC= gcc
CFLAGS= -Wall -Wextra -Werror

## Flags for the C preprocessor
CPPFLAGS= -I$(SRC_PATH) -I$(LIB)

## Libraries path
LDFLAGS= -L$(LIB)

## Libraries to link into the executable
LDLIBS= -lft

NAME=fillit

# Project related variables
SRC_PATH = src
SRC_NAME = main.c utils.c import.c create.c check.c show.c solve.c destroy.c\
			calc.c identify.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft
HEADER = $(SRC_PATH)/$(NAME).h $(SRC_PATH)/t_ref.h

# Tracks malloc() and free()
ifdef ALLOCWRAP
	LDFLAGS += $(HOME)/lib/alloc_wrap.c -ldl
endif

# Entry point
all: $(NAME)

# Compiles fillit
$(NAME): $(LIB)/$(LIB).a $(OBJ)
	$(CCC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)

# Compiles libft/libft.a
# It's a prerequisite to compile fillit
$(LIB)/$(LIB).a:
	$(MAKE) -C ./$(LIB)

# Creates obj/ directory
# It's a prerequisite to compile any OBJ
$(OBJ_PATH):
	mkdir $@

# Consider an example where your targets are to be placed in a separate
# directory, and that directory might not exist before make is run.
# In this situation, you want the directory to be created before any targets
# are placed into it but, because the timestamps on directories change whenever
# a file is added, removed, or renamed, we certainly don’t want to rebuild all
# the targets whenever the directory’s timestamp changes. One way to manage
# this is with order-only prerequisites: make the directory an order-only
# prerequisite on all the targets:
$(OBJ): | $(OBJ_PATH)


# Compiles all the src/*.c into obj/*.o
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	$(CCC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# /!\ Dirty workaround /!\
# If make on the libft directory should rebuild something then PHONY the rule
# libft to build it. Otherwise it relink.
ifeq ($(shell $(MAKE) --question -C ./$(LIB) ; echo $$?), 1)
.PHONY: $(LIB)/$(LIB).a
endif


.PHONY: clean
clean:
	$(MAKE) -C ./$(LIB) clean
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(MAKE) -C ./$(LIB) fclean
	$(RM) -r $(NAME) $(NAME).dSYM

re: fclean
	$(MAKE) all

.PHONY: norme
norme:
	norminette $(SRC)
	norminette $(HEADER)
	norminette ./$(LIB)/*.c
	norminette ./$(LIB)/*.h
