/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:20 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/04 03:11:33 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	struct sigaction sa;
	char *line;
	t_cmd *cmd;

	sig_start(&sa);

	while(1)
	{
		line = readline("minishell% "); //prompt de base
		if (!line) // Ctrl+D
			exit_free();

		// printf("%s", line);

		if (*line)
			add_history(line);

		// on parse la ligne
		cmd = parsing(line);

		// si elle est valide on l’exécute
		if (cmd && cmd->args[0])
			exec(cmd);
			
		free(line);
	}

	return (0);
}
