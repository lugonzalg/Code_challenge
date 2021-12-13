/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/13 15:05:37 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

static int	ft_control(int num[2], char *line)
{
	if (num[0] < 0 || num[0] > 6)
		return (1);
	if (num[1] < 0 || num[1] > 6)
		return (1);
	if (strlen(line) != 4)
		return (1);
	if (line[1] != ':')
		return (1);
	return (0);
}

static void	ft_get_data(void)
{
	char	*line;
	int		fd;
	int		num[2];
	size_t	i;

	i = 1;
	fd = open("submitInput.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		num[0] = atoi(line);
		num[1] = atoi(line + 2);
		if (ft_control(num, line))
		{
			printf("ERROR LINE: %zu", i++);
			continue ;
		}
		free(line);
		if (num[0] + num[1] != 12)
			printf("Case #%zu: %d\n", i, num[0] + num[1] + 1); 
		else
			printf("Case #%zd: -\n", i); 
		i++;
	}
}

int	main(void)
{
	ft_get_data();
	return (0);
}
