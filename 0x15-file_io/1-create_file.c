#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int i;
	int throw;
	int rd;

	if (!filename)
		return (-1);

	i = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (i == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (throw = 0; text_content[throw]; throw++)
		;

	rd = write(i, text_content, throw);

	if (rd == -1)
		return (-1);

	close(i);

	return (1);
}
