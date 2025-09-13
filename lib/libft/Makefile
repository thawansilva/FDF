NAME = libft.a
SRCPRINT = printf
SRCGNL = gnl
SRCS = ft_isalpha.c ft_isalnum.c ft_isdigit.c ft_memset.c\
	   ft_strlcpy.c ft_toupper.c ft_bzero.c ft_atoi.c ft_isascii.c\
	   ft_isprint.c ft_strlen.c ft_tolower.c ft_memcpy.c ft_memmove.c\
	   ft_strchr.c ft_strnstr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c\
	   ft_substr.c ft_strjoin.c ft_strdup.c ft_calloc.c ft_memchr.c\
	   ft_memcmp.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c\
	   ft_split.c ft_isspace.c\
	   $(SRCPRINT)/ft_printf.c $(SRCPRINT)/ft_print_hex.c\
	   $(SRCPRINT)/ft_print_nbr.c $(SRCPRINT)/ft_print_ptr.c\
	   $(SRCPRINT)/ft_print_str.c $(SRCPRINT)/ft_print_unbr.c\
	   $(SRCGNL)/get_next_line.c

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
		   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
		   ft_lstmap_bonus.c
OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(SRCBONUS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f
COLOR_GREEN := \033[0;32m
END_COLOR := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

bonus:
	@$(MAKE) OBJS="$(OBJS) $(BONUSOBJS)"

%.o : %.c
	@clang $(CFLAGS) -I . -c $< -o $@
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

clean:
	@$(RM) $(OBJS) $(BONUSOBJS)
	@echo "✅ $(COLOR_GREEN)Object files DELETED $(END_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "✅ $(COLOR_GREEN)$(NAME) DELETED $(END_COLOR)"

re: fclean all

.PHONY: all bonus fclean clean re 
