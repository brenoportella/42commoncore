# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:25:32 by bportell          #+#    #+#              #
#    Updated: 2024/11/11 16:23:54 by bportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_tolower.c \
			ft_atoi.c ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c \
			ft_bzero.c ft_isprint.c ft_memset.c ft_strncmp.c \
			ft_isalnum.c ft_memchr.c ft_strchr.c ft_strnstr.c \
			ft_isalpha.c ft_memcmp.c ft_strlcat.c ft_strrchr.c \
			ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c

OBJS = $(SRCS:.c=.o)

CC = cc

GCCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(GCCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Including c files (objs) into file $(NAME)"
	@ar rcs $(NAME) $(OBJS) #pesquisar o que essa linha faz principalmente o ar rcs

clean:
	@echo "Removing files OBJS"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	
re: fclean all
	@echo "All files was removed!"

.PHONY: all clean fclean re