
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (int ac, char **av)
{
	int fd;
	int ok = 1;
	char *line;

	if (!(line = (char*)malloc(sizeof(char) * 5)))
		return (0);
	fd = open("a.txt", O_RDONLY);

	while (ok > 0)
	{
		line = (char*)malloc(sizeof(char) * 5);
		ok = get_next_line(fd, &line);
		if (ok > 0)
			printf("%s\n", line);
		free(line);
		//printf("%d\n", ok);
	}

	close(fd);
	return (0);
}
