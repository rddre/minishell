/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:29:10 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/08 05:23:31 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/* getcwd renvoie le chemin absolu du repertoire courant  /
/        il alloue de la memoire donc faut free a la fin */
int		builtin_pwd(t_cmd *cmd)
{
	char *actual_directory;

	(void)cmd;
	actual_directory = getcwd(NULL, 0);
    if (!actual_directory)
    {
        perror("pwd");
        return (1);
    }
    printf("%s\n", actual_directory);
    free(actual_directory);
	return (0);
}
