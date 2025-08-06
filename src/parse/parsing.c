/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:06:05 by asaracut          #+#    #+#             */
/*   Updated: 2025/08/06 16:11:58 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	parsing() doit prendre une ligne entrée par l'utilisateur, par exemple :
		> echo hello world

	Et construire une structure représentant cette commande :
		-> cmd->args = ["echo", "hello", "world", NULL];

	Plus tard, il devra aussi gérer :
		- les quotes
		- les pipes
		- les redirections
		- les variables d'environnement

	Paramètre :
		char *line → ligne entrée par readline

	Retour :
		t_cmd * → structure représentant une commande simple
*/
t_cmd	*parsing(char *line)
{
	// prototype vide pour l’instant
	return (NULL);
}