NAME := fdf
# Directories
SRCDIR := src/
OBJDIR := obj/
INCDIR := include/ lib/libft/ lib/MLX42/include/MLX42/

# Source files and Objects
SRC := main.c 

SRC := $(SRC:%=$(SRCDIR)%)
OBJS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

# Libs
LIBMLX := lib/MLX42
LIBS := ft mlx 
LIBS_TARGET := lib/libft/libft.a

# Flags
CC := clang
CFLAGS := -Wall -Wextra -Werror -g2 -O0
CPPFLAGS := $(addprefix -I, $(INCDIR))
LDFLAGS := $(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS := $(addprefix -l, $(LIBS)) -lm

# Useful variables
RM := rm -f
RMDIR := rm -fr
DUP_DIR = mkdir -p $(@D)
COLOR_GREEN := \033[0;32m
END_COLOR := \033[0m

all: $(NAME) 

$(NAME): $(OBJS) $(LIBS_TARGET) libmlx.a
	@$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "✅ $(COLOR_GREEN)$(NAME) CREATED $(END_COLOR)"

$(LIBS_TARGET):
	@$(MAKE) -C $(@D)

libmlx.a: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(DUP_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RMDIR) $(OBJDIR)
	@echo "✅ $(COLOR_GREEN)Object Files Deleted $(END_COLOR)"

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	@$(RM) $(NAME)
	@echo "✅ $(COLOR_GREEN)$(NAME) Deleted $(END_COLOR)"

re: fclean all

.PHONY: all clean fclean re
