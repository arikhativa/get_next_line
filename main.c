
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (int ac, char **av)
{
	int fd;
	char *line;

	if (!(line = (char*)malloc(sizeof(char) * 5)))
		return (0);
	fd = open("a.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	close(fd);
	/*while (get_next_line(fd, line) != 0)
	{
		printf("%s\n", *line);
	}*/
	return (0);
}
