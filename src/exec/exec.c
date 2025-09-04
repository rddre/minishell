/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 16:35:40 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/04 02:49:28 by asaracut         ###   ########.fr       */
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
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0) // processus enfant
	{
		if (execve(cmd->args[0], cmd->args, NULL) == -1)
		{
			perror("execve");
			_exit(1);
		}
	}
	else // processus parent
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}

/*
int main(void)
{
	t_cmd cmd;
	char *args[] = {"/bin/echo", "NULL\n\n", NULL};

	cmd.args = args;
	exec(&cmd);
	printf("il revien bien au main\n");
	return 0;
}*/