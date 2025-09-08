/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:29:10 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/08 04:53:11 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*   l'argument a gerer ici est -n, ca suprime le \n a la fin de l'echo   */
int	builtin_echo(t_cmd *cmd)
{
	int	i;
	int	arg_n;

	i = 1;
	arg_n = 0;
	while (cmd->args[i] && ft_strncmp(cmd->args[i], "-n", 2) == 0
		&& cmd->args[i][2] == '\0')
	{
		arg_n = 1;
		i++;
	}
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (!arg_n)
		printf("\n");
	return (0);
}
