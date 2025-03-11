# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bportell <bportell@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:25:32 by bportell          #+#    #+#              #
#    Updated: 2025/03/11 13:20:39 by bportell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
 			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			\
			ft_printf.c ft_aux.c \
			\
			get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

OBJDIR = objs

CC = cc

GCCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(GCCFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Including c files (objs) into file $(NAME)"
	@ar rcs $(NAME) $(OBJS) #pesquisar o que essa linha faz principalmente o ar rcs

clean:
	@echo "Removing files OBJS"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	
re: fclean all
	@echo "All files was removed!"

.PHONY: all clean fclean re