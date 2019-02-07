OK_COLOR=\x1b[32;01m
DANGER_COLOR=\x1b[1;31m
YELLOW_COLOR=\x1b[0;33m
NO_COLOR=\x1b[0m

INCS_DIR = ./includes
LIBS_DIR = ./libs
SRCS_DIR = ./srcs
OBJS_DIR = ./obj

LIBS = libft libftprintf

#	Checker
CH_SRCS = checker.c stack.c call_cmd.c operations.c utils.c
CH_OBJS = $(addprefix $(OBJS_DIR)/,$(CH_SRCS:%.c=%.o))

#	Push_Swap
PS_SRCS =	push_swap.c read_args.c operations.c utils.c stack.c \
			call_cmd.c quick_sort.c partition.c
PS_OBJS = $(addprefix $(OBJS_DIR)/,$(PS_SRCS:%.c=%.o))

FLAGS += -Wall -Wextra -Werror
#FLAGS += -g -O0

INCS_FLAGS += -I$(INCS_DIR)
INCS_FLAGS += $(foreach lib,$(LIBS),-I$(LIBS_DIR)/$(lib)/includes)

LIBS_FLAGS += $(foreach lib,$(LIBS),-L$(LIBS_DIR)/$(lib) -l$(lib:lib%=%))

################################################################################

all: $(LIBS) checker push_swap

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@gcc $(FLAGS) $(INCS_FLAGS) -c $< -o $@

libft:
	@echo "$(YELLOW_COLOR)Make $@...$(NO_COLOR)"
	@$(MAKE) -C $(LIBS_DIR)/libft
	@echo "$(OK_COLOR)Complete$(NO_COLOR)"

libftprintf:
	@echo "$(YELLOW_COLOR)Make $@...$(NO_COLOR)"
	@$(MAKE) -C $(LIBS_DIR)/libftprintf
	@echo "$(OK_COLOR)Complete$(NO_COLOR)"

############################		 checker		############################

$(CH_OBJS): | $(OBJS_DIR)

checker: $(CH_OBJS)
	@echo "$(YELLOW_COLOR)Make $@...$(NO_COLOR)"
	@gcc $(FLAGS) $(INCS_FLAGS) $(LIBS_FLAGS) $^ -o $@
	@echo "$(OK_COLOR)Complete$(NO_COLOR)"

################################	push_swap	################################

$(PS_OBJS): | $(OBJS_DIR)

push_swap: $(PS_OBJS)
	@echo "$(YELLOW_COLOR)Make $@...$(NO_COLOR)"
	@gcc $(FLAGS) $(INCS_FLAGS) $(LIBS_FLAGS) $^ -o $@
	@echo "$(OK_COLOR)Complete$(NO_COLOR)"

################################################################################

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(DANGER_COLOR)Object files cleared$(NO_COLOR)"

fclean: clean
	@rm -f checker
	@rm -f push_swap
	@echo "$(DANGER_COLOR)Build cleared$(NO_COLOR)"

re: fclean all

.PHONY: all re clean fclean