#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int fd;
	int ret;
	char *line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (ret = get_next_line(fd, &line))
		{
			printf("ret = %d | ", ret);
			printf("%s\n", line);
		}
		printf("ret = %d | ", ret);
	}
	return (0);
}
