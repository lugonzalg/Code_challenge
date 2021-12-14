#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line[i])
		{
			if (isupper(line[i]))
				printf("%c", line[i]);
			i++;
		}
		printf("\n");
	}
}
