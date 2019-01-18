FLAGS += -Wall -Wextra -Werror
FLAGS += -g

INCS_DIR = ./includes
LIBS_DIR = ./libs
SRCS_DIR = ./srcs

LIBS = libft
SRCS = srcs/checker.c srcs/operations.c

FLAGS += -I$(INCS_DIR)
FLAGS += $(foreach lib,$(LIBS),\
	-I$(LIBS_DIR)/$(lib)/includes \
	-L$(LIBS_DIR)/$(lib) \
	-l$(lib:lib%=%))

all: checker

checker: 
	$(MAKE) -C $(LIBS_DIR)/libft
	gcc $(FLAGS) $(SRCS)

re: all

.PHONY: all re clean fclean