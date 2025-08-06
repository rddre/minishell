/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:35:40 by asaracut          #+#    #+#             */
/*   Updated: 2025/08/06 16:35:44 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
	exec() reçoit une structure t_cmd générée par le parsing :

	Exemple d’entrée :
		t_cmd *cmd;
		cmd->args = ["echo", "hello", "world", NULL];

	Objectif :
		→ exécuter la commande avec execve ou équivalent
		→ gérer les erreurs si la commande est inconnue
		→ plus tard : gérer les pipes et redirections

	Paramètre :
		t_cmd *cmd → structure contenant la commande et ses arguments

	Retour :
		int → code de sortie du programme exécuté (utile plus tard pour $?)
*/
int	exec(t_cmd *cmd)
{
	// prototype vide pour l’instant
	return (0);
}