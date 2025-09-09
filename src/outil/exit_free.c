/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:17:01 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/09 03:14:01 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void free_all(t_cmd *cmd, t_shell *shell)
{
	int i;

	if (cmd)
	{
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
		}
		free(cmd);
	}
	if (shell && shell->env)
	{
		i = 0;
		while (shell->env[i])
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
}

void exit_free(t_cmd *cmd, t_shell *shell, int exit_code)
{
	free_all(cmd, shell);
	printf("exit\n");
	exit(exit_code);
}