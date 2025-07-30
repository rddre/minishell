/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:20 by asaracut          #+#    #+#             */
/*   Updated: 2025/07/30 02:29:04 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	struct sigaction sa;
	char *line;

	sig_start(&sa);

	while(1)
	{
		line = readline("minishell% "); //prompt de base
		if (!line) // Ctrl+D
			exit_free();

		printf("%s", line);

		if (*line)
			add_history(line);
			
		free(line);
	}

	return (0);
}
