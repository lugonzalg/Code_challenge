/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 03:13:03 by lugonzal         ###   ########.fr       */
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

extern void	*ft_free_d2(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static void	ft_add_back(t_scale *node, t_scale **head)
{
	t_scale *tmp;

	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

static t_scale	*ft_create_scale(t_scale *head)
{
	char	*line;
	int		fd;
	char	**tab;
	t_scale	*node;

	fd = open("scale.txt", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
			break ;
		line[strlen(line) - 1] = 0;
		tab = ft_split(line, ' ');
		if (!tab)
			return (ft_free_d2(tab));
		node = calloc(sizeof(t_scale), 1);
		if (!node)
			return (NULL);
		node->tone = ft_strdup(tab[0]);
		if (tab[1])
			node->semi = ft_strdup(tab[1]);
		ft_free_d2(tab);
		ft_add_back(node, &head);
	}
	node->next = head;
	close(fd);
	return (head);
}

static void	ft_scale(int fd)
{
	char	*line;
	t_scale	*head;
	int		loop;

	head = NULL;
	head = ft_create_scale(head);
	line = get_next_line(fd);
	loop = atoi(line);
	free(line);
	while (loop--)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[strlen(line) - 1] = 0;
		ft_get_acorde(line, head, fd);
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (2);
	ft_scale(fd);
	close(fd);
	return (0);
}
