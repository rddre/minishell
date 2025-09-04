/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:06:05 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/04 03:01:10 by asaracut         ###   ########.fr       */
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
	t_cmd	*cmd;
	char	*token;
	int		count = 0;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);

	// Compter les mots
	char *tmp = strdup(line);
	token = strtok(tmp, " \t\n");
	while (token)
	{
		count++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp);

	// Allouer args
	cmd->args = malloc(sizeof(char *) * (count + 1));
	if (!cmd->args)
		return (NULL);

	// Découper vraiment
	int i = 0;
	token = strtok(line, " \t\n");
	while (token)
	{
		cmd->args[i++] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	cmd->args[i] = NULL; // fin du tableau

	return cmd;
}
