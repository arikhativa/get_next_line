
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
	char *line;

	int fd = open("testfile.txt", O_RDONLY);
    if(fd < 0)
        return 1;
	
	line = get_next_line(fd);
	if (!line)
		printf("%s", "ERROR\n");
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}