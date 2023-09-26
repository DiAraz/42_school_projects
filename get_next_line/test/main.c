#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "../get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	printf("---------------------------\nBUFFER_SIZE\t=\t%llu\n---------------------------\n", (unsigned long long int)BUFFER_SIZE);
	
	if (argc != 2)
	{
		printf("No file to read.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("File cannot be read.\n");
		return (0);
	}
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
