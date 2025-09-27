NAME := fdf
# Directories
SRCDIR := src
OBJDIR := obj
MLXDIR := lib/MLX42
INCDIR := include lib/libft $(MLXDIR)/include

# Source files and Objects
SRC := main.c error_msg.c free_memory.c maps/init_map.c maps/validate_map.c\
	   maps/draw_map.c images/create_images.c images/draw_menu.c\
	   bresenham/bresenham.c\

SRC := $(SRC:%=$(SRCDIR)/%)
OBJS := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libs
LIBS := ft mlx42 dl glfw m
LIBMLX := $(MLXDIR)/build/libmlx42.a
LIBS_TARGET := lib/libft/libft.a

# Flags
CC := clang
CFLAGS := -Wall -Wextra -Werror -g2 -O0
CPPFLAGS := $(addprefix -I, $(INCDIR))
LDFLAGS := $(addprefix -L, $(dir $(LIBS_TARGET))) -L$(MLXDIR)/build
LDLIBS := $(addprefix -l, $(LIBS)) -pthread

# Useful variables
RM := rm -f
RMDIR := rm -fr
DUP_DIR = mkdir -p $(@D)
COLOR_GREEN := \033[0;32m
END_COLOR := \033[0m

all: $(NAME) 

$(NAME): $(OBJS) $(LIBS_TARGET) $(LIBMLX)
	@$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "✅ $(COLOR_GREEN)$(NAME) CREATED $(END_COLOR)"

$(LIBS_TARGET):
	@$(MAKE) -C $(@D)

$(LIBMLX): 
	@cmake $(MLXDIR) -B $(MLXDIR)/build
	@make -C $(MLXDIR)/build -j4 DEBUG=1
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(DUP_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "✅ $(COLOR_GREEN)$@ CREATED $(END_COLOR)"

clean:
	@$(RMDIR) $(OBJDIR)
	@echo "✅ $(COLOR_GREEN)Fdf Object Files DELETED $(END_COLOR)"

fclean: clean
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	@$(RM) $(NAME) $(LIBMLX)
	@echo "✅ $(COLOR_GREEN)$(NAME) and libmlx42.a DELETED $(END_COLOR)"

re: fclean all

.PHONY: all clean fclean re
