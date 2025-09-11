/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:17:01 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/11 01:59:04 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void free_cmd(t_cmd *cmd)
{
	int i = 0;

	if (!cmd)
		return ;
	if (cmd->args)
	{
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
	}
	free(cmd);
}

void free_shell(t_shell *shell)
{
	int i = 0;

	if (!shell)
		return ;
	if (shell->env)
	{
		while (shell->env[i])
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
}

void free_all(t_cmd *cmd, t_shell *shell)
{
	free_cmd(cmd);
	free_shell(shell);
	rl_clear_history();
}

void exit_free(t_cmd *cmd, t_shell *shell, int exit_code)
{
	free_all(cmd, shell);
	printf("exit\n");
	exit(exit_code);
}