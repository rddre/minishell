/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 01:28:02 by asaracut          #+#    #+#             */
/*   Updated: 2025/07/30 02:18:41 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// saute une ligne | efface la ligne courante | repositionne le curseur |affiche à nouveau le prompt
void ctrl_c(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void sig_start(struct sigaction *sa)
{
	sa->sa_handler = ctrl_c;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_RESTART;

	sigaction(SIGINT, sa, NULL); // ctrl c 
	signal(SIGQUIT, SIG_IGN);    // fait rien pour ctrl back slash
}
