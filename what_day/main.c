/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/14 20:43:57 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#include "days.h"
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

static char	***ft_fill_dict(int fd)
{
	char	***dict;
	char	**tab;
	char	*line;
	size_t	i;

	dict = calloc(sizeof(char **), 21);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab = ft_split(line, ',');
		if (!tab)
			break ;
		dict[i++] = tab;
	}
	return (dict);
}

static void	ft_mode_1(int value[4], char **tab)
{
	value[0] = atoi(tab[0] + 2);
	tab[0][2] = 0;
	value[1] = atoi(tab[0]);
	value[2] = atoi(tab[1]);
	value[3] = atoi(tab[2]);
}

static void	ft_mode_2(int value[4], char **tab)
{
	value[2] = atoi(tab[0]);
	value[3] = atoi(tab[1]);
	value[0] = atoi(tab[2] + 2);
	tab[2][2] = 0;
	value[1] = atoi(tab[2]);
}

static int	ft_calculate(char *date)
{
	char	**tab;
	int		value[4];

	tab = ft_split(date, '-');
	if (strlen(tab[0]) == 4)
		ft_mode_1(value, tab);
	else
		ft_mode_2(value, tab);
	return (0);
}

static void	ft_print_days(char ***dict, int fd)
{
	char	*line;
	char	**tab;
	int		loop;

	line = get_next_line(fd);
	loop = atoi(line);
	free(line);
	(void)dict;
	while (loop--)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tab = ft_split(line, ':');
		ft_calculate(tab[0]);
	}
}

int	main(int argc, char **argv)
{
	char	***dict;
	int	fd;

	if (argc != 2)
		return (1);
	fd = open("days.txt", O_RDONLY);
	if (fd == -1)
		return (2);
	close(fd);
	dict = ft_fill_dict(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (2);
	ft_print_days(dict, fd);
	return (0);
}
