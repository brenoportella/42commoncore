# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 10:04:52 by bportell          #+#    #+#              #
#    Updated: 2024/11/20 14:16:33 by bportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_aux.c 

OBJS = $(SRCS:.c=.o)

CC = cc

GCCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(GCCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Including c files (objs) into file $(NAME)"
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "Removing files OBJS"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	
re: fclean all
	@echo "All files was removed!"

.PHONY: all clean fclean re