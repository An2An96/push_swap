FLAGS += -Wall -Wextra -Werror
FLAGS += -g

INCS_DIR = ./includes
LIBS_DIR = ./libs
SRCS_DIR = ./srcs
OBJS_DIR = ./obj

LIBS = libft

CH_SRCS = checker.c call_cmd.c operations.c
CH_OBJS = $(addprefix $(OBJS_DIR)/,$(CH_SRCS:%.c=%.o))

PS_SRCS = push_swap.c operations.c call_cmd.c insertion_sort.c bubble_sort.c
PS_OBJS = $(addprefix $(OBJS_DIR)/,$(PS_SRCS:%.c=%.o))

INCS_FLAGS += -I$(INCS_DIR)
INCS_FLAGS += $(foreach lib,$(LIBS),-I$(LIBS_DIR)/$(lib)/includes)

#FLAGS += -I$(INCS_DIR)
#FLAGS += $(foreach lib,$(LIBS),\
	-I$(LIBS_DIR)/$(lib)/includes \
	-L$(LIBS_DIR)/$(lib) \
	-l$(lib:lib%=%))

LIBS_FLAGS += $(foreach lib,$(LIBS),-L$(LIBS_DIR)/$(lib) -l$(lib:lib%=%))

################################################################################

all: libft checker push_swap

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	gcc $(FLAGS) $(INCS_FLAGS) -c $< -o $@

libft:
	@echo "Make $@..."
	@$(MAKE) -C $(LIBS_DIR)/libft
	@echo "Complete"

############################		 checker		############################

$(CH_OBJS): | $(OBJS_DIR)

checker: $(CH_OBJS)
	@echo "Make $@..."
	@gcc $(FLAGS) $(INCS_FLAGS) $(LIBS_FLAGS) $^ -o $@
	@echo "Complete"

################################	push_swap	################################

$(PS_OBJS): | $(OBJS_DIR)

push_swap: $(PS_OBJS)
	@echo "Make $@..."
	gcc $(FLAGS) $(INCS_FLAGS) $(LIBS_FLAGS) $^ -o $@
	@echo "Complete"

################################################################################

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Object files cleared"

fclean: clean
	@rm -f checker
	@rm -f push_swap
	@echo "Build cleared"

re: fclean all

.PHONY: all re clean fclean