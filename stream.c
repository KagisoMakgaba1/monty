#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * get_stream_fail - Handles the error when reading a file fails.
 * @fileName: The name of the file that failed to open.
 */

void get_stream_fail(char *fileName)
{
	fprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_args();
	exit(EXIT_FAILURE);
}



/**
 * get_stream - gets the stream for reading from the specified file.
 * @fileName: Name of the file to open and set as the stream.
 */

void get_stream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		get_stream_fail(fileName);

	arguments->stream = fdopen(fd, "r");
	if (arguments->stream == NULL)
	{
		close(fd);
		get_stream_fail(fileName);
	}
}
