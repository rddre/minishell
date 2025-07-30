# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 02:20:26 by asaracut          #+#    #+#              #
#    Updated: 2025/07/30 02:27:20 by asaracut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D_POSIX_C_SOURCE=200809L
SRC = src/minishell.c \
      src/sig/sig.c src/outil/exit_free.c
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)
	@echo "✅ Compilation terminée."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline -lncurses
	@rm -f $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re