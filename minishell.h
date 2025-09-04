/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:15 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/04 02:44:19 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define _POSIX_C_SOURCE 200809L // a mettre avant tout les include pour definir la version pour les sig
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_cmd
{
	char	**args;
}	t_cmd;

t_cmd	*parsing(char *line);
int		exec(t_cmd *cmd);


/*           sig              */
void ctrl_c(int signo);
void sig_start(struct sigaction *sa);

/*          free exit           */
void exit_free(void);

#endif