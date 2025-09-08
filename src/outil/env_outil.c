/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_outil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 05:37:35 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/08 05:38:04 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char **copy_env(char **envp)
{
    int count = 0;
    char **new_env;

    while (envp[count])
        count++;

    new_env = malloc(sizeof(char *) * (count + 1));
    if (!new_env)
        return NULL;

    for (int i = 0; i < count; i++)
        new_env[i] = strdup(envp[i]);
    new_env[count] = NULL;

    return new_env;
}
