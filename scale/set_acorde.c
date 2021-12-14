/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_acorde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:41:04 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 03:11:25 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "scale.h"
#include "get_next_line.h"

static int	ft_check_acord(char *acord, char *tone, char *first)
{
	if (ft_strchr(acord, *tone) && strcmp(tone, first))
		return (0);
	return (1);
}

extern void	ft_get_acorde(char *line, t_scale *head, int fd)
{
	size_t		i;
	char		*acord;
	static int	j = 1;
	char		*first;

	acord = calloc(sizeof(char), 20),
	i = -1;
	memcpy(acord, line, strlen(line));
	while (1)
	{
		if (!strcmp(head->tone, line) || (head->semi && !strcmp(head->semi, line)))
			break ;
		head = head->next;
	}
	free(line);
	line = get_next_line(fd);
	line[strlen(line) - 1] = 0;
	first = ft_strdup(acord);
	while (line[++i])
	{
		if (line[i] == 'T')
			head = head->next->next;
		else
			head = head->next;
		if (!head->semi || ft_check_acord(acord, head->tone, first))
			memcpy(acord + strlen(acord), head->tone, strlen(head->tone));
		else
			memcpy(acord + strlen(acord), head->semi, strlen(head->semi));
	}
	printf("Case #%d: %s\n", j++, acord);
}
