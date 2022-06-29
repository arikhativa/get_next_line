
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#include "get_next_line.h"

int main()
{
	char *line1;
	char *line;
	int fd;
	int fd1;

	fd = open("testfile.txt", O_RDONLY);
	if (0 > fd)
		return (1);
	fd1 = open("tttt.txt", O_RDONLY);
	if (0 > fd1)
		return (1);
	line1 = get_next_line(fd1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	while (line1)
	{
		printf("%s", line1);
		free(line1);
		line1 = get_next_line(fd1);
	}
}