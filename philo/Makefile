# ==================== #
#    Color Settings    #
# ==================== #
BOLD    = \033[1m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
RESET   = \033[0m

# Compiler & Flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -pthread -Iincludes

# Directories
SRCDIR 	= src
OBJDIR  = obj

# Sources & Objects
SOURCES = actions.c clean.c init.c main.c monitor.c simulation.c utils.c
SRCS	= $(addprefix $(SRCDIR)/, $(SOURCES))
OBJS    = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

# Output Binary
NAME    = philo

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Build complete: $(NAME)$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Removing binary...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re