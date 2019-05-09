#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int fd2;
	int out;
	int ok;
	char *line;
	int p[2];

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n", 4);
	close(p[1]);
	dup2(out, fd);
	ac = 0;
	//fd2 = open(av[1], O_RDONLY);
	while (ac++ < 2)
	{
		//ok = get_next_line(fd2, &line);

		ok = get_next_line(p[0], &line);

		printf("ok   == %d\n", ok);
		printf("line == %s\n", line);
	}
	return (0);
}
