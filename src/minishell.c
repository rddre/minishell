/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:20 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/09 03:14:34 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ici je check si la commande est un builtin
int is_builtin(char *cmd)
{
    if (!cmd)
        return (0);
    if (strcmp(cmd, "echo") == 0)
        return (1);
    if (strcmp(cmd, "cd") == 0)
        return (1);
    if (strcmp(cmd, "pwd") == 0)
        return (1);
    if (strcmp(cmd, "export") == 0)
        return (1);
    if (strcmp(cmd, "unset") == 0)
        return (1);
    if (strcmp(cmd, "env") == 0)
        return (1);
    if (strcmp(cmd, "exit") == 0)
        return (1);
    return (0);
}

/* cmd c'est la ligne de commande / shell c'est l'environement */
int	main(int argc, char **argv, char **envp)
{
	struct sigaction sa;
	char *line;
	t_cmd *cmd;
	t_shell shell;

    (void)argc;
    (void)argv;

	sig_start(&sa);
	shell.env = copy_env(envp);
	
	while(1)
	{
		line = readline("minishell% "); //prompt de base
		if (!line) // Ctrl+D
			exit_free(cmd, &shell, 0);

		// printf("%s", line);

		if (*line)
			add_history(line);

		// on parse la ligne
		cmd = parsing(line);

		// si elle est valide on l’exécute aussi je check si c’est un builtin
		if (cmd && cmd->args[0])
		{
		if (is_builtin(cmd->args[0]))
			exec_builtin(cmd, &shell);
		else
			exec(cmd);
		}
			
		free(line);
	}

	return (0);
}
