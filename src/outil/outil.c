/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaracut <asaracut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 03:26:18 by asaracut          #+#    #+#             */
/*   Updated: 2025/09/09 03:04:47 by asaracut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char *ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == (char)c)
			return ((char *)string);
		string++;
	}
	if (c == '\0')
		return ((char *)string);
	return (NULL);
}

int is_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		symbole;
	size_t	result;

	result = 0;
	symbole = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			symbole *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && result < LONG_MAX)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > LONG_MAX && symbole == 1)
		return (-1);
	else if (result > LONG_MAX)
		return (0);
	return (result * symbole);
}
