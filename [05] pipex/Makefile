# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 12:39:58 by bportell          #+#    #+#              #
#    Updated: 2025/03/11 13:29:44 by bportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME = pipex
LIBFT = ./inc/libft/libft.a

# SRC AND OBJ
MAIN = pipex_main.c
SOURCES = pipex_aux.c 

SRCS_DIR = srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))

# COMMANDS AND FLAGS
CC = cc
CCFLAGS = -Wall -Wextra -Werror
VAL = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s
FDFLAGS = --trace-children=yes --track-fds=yes

# MAIN RULES
all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT)
	@echo "Compiling: $(NAME)..."
	@$(CC) $(CCFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Done: Compiling $(NAME)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "Creating: Objects..."
	@$(CC) $(CCFLAGS) -c $< -o $@
	@echo "Done: Creating Objects"

$(OBJS_DIR):
	@echo "Creating /objs folder"
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Compiling: LIBFT"
	@make -C ./inc/libft -s
	@echo "Done: Compiling LIBFT"

# EXECUTION RULES
exe_clean:
	rm -rf infile*
	rm -rf outfile*

# BASIC RULES
clean: exe_clean
	@echo "Removing files /objs"
	@rm -rf $(OBJS_DIR)
	@echo "Removing files libft/objs"
	@make clean -C ./inc/libft -s
	@echo "Done: Removing files"

fclean: clean
	@echo "Removing: $(NAME)"
	@rm -rf $(NAME)
	@echo "Removing: $(LIBFT)"
	@rm -rf $(LIBFT)
	@echo "Done: Remove $(NAME), $(LIBFT)"
	
re: fclean all
	@echo "You RE-Did it!"

.PHONY: all clean fclean re exe_clean