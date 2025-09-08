/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:15 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/08 05:52:06 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L // a mettre avant tout les include pour definir la version pour les sig
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char	**args;
}			t_cmd;

/* copie de l'environnement */
typedef struct s_shell
{
    char    **env;   
}   t_shell;

/*		 parsing / exec         */
t_cmd	*parsing(char *line);
int		exec(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd, t_shell *shell);

/*       builtins            */
int		builtin_echo(t_cmd *cmd);
int		builtin_cd(t_cmd *cmd);
int		builtin_pwd(t_cmd *cmd);
int		builtin_export(t_cmd *cmd);
int		builtin_unset(t_cmd *cmd);
int		builtin_env(char **environ);
int		builtin_exit(t_cmd *cmd);

/*           sig              */
void	ctrl_c(int signo);
void	sig_start(struct sigaction *sa);

/*          free exit           */
void	exit_free(void);

/*          outils              */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *string, int c);
char	**copy_env(char **envp);

#endif