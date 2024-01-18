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
