/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/13 22:48:53 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "catch.h"
#include "get_next_line.h"

static void	ft_get_tab(int fd, t_info *info, size_t	row, size_t	col)
{
	char	*line;
	size_t	i;
	size_t	j;

	info->tab = calloc(sizeof(char), row * col + 1);
	i = 0;
	while (row--)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[strlen(line) - 1] =  0;
		j = -1;
		while (line[++j])
		{
			if (line[j] == SPACE)
				continue ;
			info->tab[i++] = line[j];
		}
	}

}

static void	ft_free_d2(char	**tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static void	ft_reversed(t_info *info, size_t i)
{
	size_t	len;
	size_t	j;

	len = strlen(info->poke[i - 1]);
	j = 0;
	info->poke[i] = ft_calloc(sizeof(char), strlen(info->poke[i - 1]) + 1);
	while (len--)
	{
		info->poke[i][j] = info->poke[i - 1][len];
		j++;
	}

}

static void	ft_create_tab(int fd, t_info *info)
{
	char	*line;
	char	**tmp;
	int		i;
	size_t	j;

	line = get_next_line(fd);
	if (!line)
		return ;
	tmp = ft_split(line, ' ');
	free(line);
	if (!tmp)
		return ;
	i = atoi(tmp[0]);
	info->poke = calloc(sizeof(char *), (i * 2) + 1);
	j = 0;
	while (i--)
	{
		line = get_next_line(fd);	
		if (!line)
			break ;
		line[strlen(line) - 1] =  0;
		info->poke[j++] = line;
		ft_reversed(info, j++);
	}
	ft_get_tab(fd, info, atoi(tmp[1]), atoi(tmp[2]));
	ft_free_d2(tmp);
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int		fd;
	int		loop;
	size_t	i;
	int		size[2];

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	loop = atoi(line);
	free(line);
	i = 1;
	while (loop--)
	{
		ft_create_tab(fd, &info);
		while (1)
		{
			size[0] = strlen(info.tab);
			size[1] = ft_catch(&info);
			if (size[0] == size[1])
				break ;
		}
		printf("Case #%zu: %s\n", i, info.tab);
		i++;
	}
	return (0);
}
