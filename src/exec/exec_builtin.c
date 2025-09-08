/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:35:40 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/08 05:52:53 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// je renvoi vers la fonction du builtin correspondant
int	exec_builtin(t_cmd *cmd, t_shell *shell)
{
	(void)shell;
    if (!cmd || !cmd->args || !cmd->args[0])
        return (1);
    if (strcmp(cmd->args[0], "echo") == 0)
        return (builtin_echo(cmd));
    else if (strcmp(cmd->args[0], "cd") == 0)
        return (builtin_cd(cmd));
    else if (strcmp(cmd->args[0], "pwd") == 0)
        return (builtin_pwd(cmd));
    else if (strcmp(cmd->args[0], "export") == 0)
        return (builtin_export(cmd));
    else if (strcmp(cmd->args[0], "unset") == 0)
        return (builtin_unset(cmd));
    else if (strcmp(cmd->args[0], "env") == 0)
        return (builtin_env(shell->env));
    else if (strcmp(cmd->args[0], "exit") == 0)
        return (builtin_exit(cmd));

    return (1);
}
