# get_next_line

<p align="center">
  <img src="https://github.com/DiAraz/DiAraz/blob/main/42_badges/get_next_linee.png" />
</p>


The 42 school's get_next_line project is where we learn to read from a file descriptor, as well as the use of static variables.

This function returns a single line from a given file descriptor. If called in a loop, get_next_line returns the entire contents of a file, line by line until it reaches the end of the file. It can be compiled specifying any buffer size.


## Usage
This function is not a stand-alone program, its files must be included and compiled within another project.

Example ``main.c``:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	/* while (line != NULL)          // for the entire contents of the given file
	{
		line = get_next_line(fd);
		printf("%s", line);
	} */

	line = get_next_line(fd);        // for one line
		printf("%s", line);

	fd = close(fd);
	return (0);
}
```
Compilation:
```bash
gcc main.c get_next_line.c get_next_line_utils.c
```
``BUFFER_SIZE`` can be specified at compilation to override the default ``BUFFER_SIZE``:
```bash
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```
Execution:
```bash
./a.out [file]
```
Depend on what you chose, the output should show the one line or the entire content of the given file.
