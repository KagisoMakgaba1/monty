#include "monty.h"

/**
 * tokenize - Tokenizes the line read from file.
 */

void tokenize(void)
{
	int i = 0;
	char *delims = " \n", *token = NULL, *strdup = NULL;

	strdup = malloc(sizeof(char) * (strlen(arguments->line) + 1));
	strcpy(strdup, arguments->line);

	arguments->n_tokens = 0;
	token = strtok(strdup, delims);

	while (token)
	{
		arguments->n_tokens += 1;
		arguments->tokens = realloc(arguments->tokens,
				sizeof(char *) * (arguments->n_tokens + 1));
		if (arguments->tokens == NULL)
		{
			fprintf(stderr, "Error reallocating memory.\n");
			exit(1);
		}
		arguments->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (arguments->tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_args();
			exit(EXIT_FAILURE);
		}
		strcpy(arguments->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	arguments->tokens[i] = NULL;
	free(strdup);
}
