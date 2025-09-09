/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:29:10 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/09 03:31:33 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		builtin_exit(t_cmd *cmd, t_shell *shell)
{
	(void)cmd;
	if (!cmd->args[1])
	{
		exit_free(cmd, shell, 0);
	}
	if (cmd->args[2])
	{
		write(2, "exit: too many arguments\n", 26);
		return (1);
	}
	if (!is_number(cmd->args[1]))
	{
		printf("exit\n");
		write(2, "exit: numeric argument required\n", 33);
		free_all(cmd, shell);
		exit(2);
	}
	else
	{
		exit_free(cmd, shell, (atoi(cmd->args[1]) % 256));
		exit(ft_atoi(cmd->args[1]));
	}
	return (0);
}
