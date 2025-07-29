/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:49:20 by asaracut          #+#    #+#             */
/*   Updated: 2025/07/30 01:17:41 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	char	*line;

	while(1)
	{
		line = readline("minishell% "); //prompt de base
		if (!line) // Ctrl+D
        {
            printf("exit\n");
            break;
        }

		printf("%s", line);

		if (*line)
			add_history(line);
			
		free(line);
	}

	return (0);
}
