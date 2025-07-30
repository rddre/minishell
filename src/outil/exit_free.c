/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:17:01 by asaracut          #+#    #+#             */
/*   Updated: 2025/07/30 02:28:55 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void exit_free(void)
{
	printf("exit\n");
	// pour l'instant rien a free a voir plus tard
	exit(0);
}