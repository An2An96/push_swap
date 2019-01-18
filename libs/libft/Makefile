NAME = libft.a

FLAGS = -g -Wall -Werror -Wextra

INC_DIR = ./includes
SRCS_DIR = ./srcs
OBJS_DIR = ./obj

FUNCS =	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
		ft_isdigit ft_isprint ft_memccpy ft_memchr ft_memcmp \
		ft_memcpy ft_memmove ft_memset ft_putchar ft_putstr \
		ft_strcat ft_strchr ft_strcmp ft_strcpy ft_strdup \
		ft_strlcat ft_strlen ft_strncat ft_strncmp ft_strncpy \
		ft_strnstr ft_strrchr ft_strstr ft_tolower ft_toupper \
		ft_strlower ft_strupper \
		ft_memalloc ft_memdel ft_memdel ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ \
		ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit \
		ft_itoa_base ft_itoa ft_dtoa ft_putendl ft_putnbr \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
		ft_strnew ft_printchr ft_str_fixlen \
		ft_pow ft_stoa ft_str_fixlen ft_uitoa_base \
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
		ft_lstmap ft_lstpush ft_lstremove

SRCS = $(foreach func,$(FUNCS),$(SRCS_DIR)/$(func).c)
OBJ = $(foreach func,$(FUNCS),$(OBJS_DIR)/$(func).o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Building...\n"
	@ar rc $@ $^
	@ranlib $@
	@echo "Build complete"

$(OBJ): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@gcc $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@echo "Object files cleared"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "Build cleared"

re: fclean copy all

.PHONY: all clean fclean re