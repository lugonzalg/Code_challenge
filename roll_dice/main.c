/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:02 by lugonzal          #+#    #+#             */
/*   Updated: 2021/12/13 14:04:21 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

static void	ft_get_data(void)
{
	char	*line;
	int		fd;
	int		num[2];
	size_t	i;

	i = 1;
	fd = open("testInput.txt", O_RDONLY);
	line = get_next_line(fd);
	free(line);
	while (1)
	{
		ft_memset(num, 0, sizeof(int) * 2);
		line = get_next_line(fd);
		if (!line)
			break ;
		num[0] = ft_atoi(line);
		num[1] = ft_atoi(line + 2);
		free(line);
		if (num[0] + num[1] != 12)
			printf("Case #%zu: %d\n", i, num[0] + num[1] + 1); 
		else
			printf("Case #5: -\n"); 
		i++;
	}
}

int	main(void)
{
	ft_get_data();
	return (0);
}
