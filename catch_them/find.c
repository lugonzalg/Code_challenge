/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:02:21 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/13 22:47:56 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "catch.h"
#include "libft.h"
#include "get_next_line.h"

static char *ft_update(char *str, char *key, size_t i)
{
	char	*n_str;
	size_t	key_len;

	key_len = strlen(key);
	n_str = calloc(sizeof(char), strlen(str) + 1);
	ft_memcpy(n_str, str, i);
	ft_memcpy(n_str + i, str + i + key_len, strlen(str + i + key_len));
	free(str);
	return (n_str);
}

extern int	ft_catch(t_info *info)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (info->tab[++i])
	{
		j = -1;
		while (info->poke[++j])
		{
			if (!strncmp(info->tab + i, info->poke[j], strlen(info->poke[j])))
				info->tab = ft_update(info->tab, info->poke[j], i);
		}
	}
	return (strlen(info->tab));
}
