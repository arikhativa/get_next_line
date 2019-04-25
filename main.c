
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (int ac, char **av)
{
	int fd;
	int ok;
	char *line;
	int i = 0;

	if (!(line = (char*)malloc(sizeof(char) * 5)))
		return (0);
	fd = open("a.txt", O_RDONLY);

	while (i < 2)
	{
		ok = get_next_line(fd, &line);
		printf("%s\n", line);
		printf("%d\n", ok);
		i++;
	}

	close(fd);
	return (0);
}
