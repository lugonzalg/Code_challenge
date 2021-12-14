/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 00:41:19 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "hate.h"
#include "get_next_line.h"

extern void	ft_free_d2(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	ft_write_dict(char **dict, t_dict **head, char **data)
{
	size_t	i;
	char	*tmp;

	i = -1;
	(void)head;
	while (dict[++i])
	{
		tmp = ft_strtrim(dict[i], " {}()[]'");
		free(dict[i]);
		dict[i] = tmp;
	}
	ft_create_list_1(dict, head);
	ft_free_d2(dict);
	ft_print_winner(*head, data); 
}

static char	**ft_dict_page(char *line, t_dict **head)
{
	char	**pages;
	char	**data;
	char	**dict;

	pages = ft_split(line, '|');
	if (!pages)
		return (NULL);
	data = ft_split(pages[0], '-');
	if (!data)
		return (NULL);
	ft_substitute(pages[1]);
	dict = ft_split(pages[1], ',');
	if (!dict)
		return (NULL);
	ft_free_d2(pages);
	ft_write_dict(dict, head, data);
	return (NULL);
}

static t_dict	*ft_create_dict(int fd)
{
	char	*line;
	t_dict	*head;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_dict_page(line, &head);
		ft_free_head(head);
		head = NULL;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_dict	*head;
	char	*line;
	int		fd;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (3);
	line = get_next_line(fd);
	free(line);
	head = ft_create_dict(fd);
	if (!head)
		return (2);
	return (0);
}
