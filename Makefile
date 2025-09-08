# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/29 02:20:26 by asaracut          #+#    #+#              #
#    Updated: 2025/09/08 05:41:22 by asaracut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -D_POSIX_C_SOURCE=200809L
SRC = src/minishell.c \
		src/parse/parsing.c src/exec/exec.c \
		src/exec/exec_builtin.c \
		src/builtin/cd.c src/builtin/echo.c src/builtin/env.c \
		src/builtin/exit.c src/builtin/export.c src/builtin/pwd.c \
		src/builtin/unset.c \
		src/sig/sig.c src/outil/exit_free.c src/outil/outil.c \
		src/outil/env_outil.c
OBJDIR  = obj
OBJ     = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline
	@echo "✅ Compilation terminée."

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🛠️  Compilation de $<"

nothing:
	@echo "🔄 fini, programme à jour."

$(NAME): nothing

clean:
	@rm -rf $(OBJDIR)
	@echo "🧹 Nettoyage des objets terminé."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️  Suppression de l'exécutable."

re: fclean all

.PHONY: all clean fclean re nothing