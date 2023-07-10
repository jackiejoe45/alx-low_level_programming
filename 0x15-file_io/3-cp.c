#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocateBuffer(char *file);
void closeFile(int fd);

/**
 * allocateBuffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file for which the buffer is being allocated.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *allocateBuffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * closeFile - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void closeFile(int fd)
{
	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, read_bytes, write_bytes;
	char *buffer;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocateBuffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	read_bytes = read(file_from, buffer, 1024);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (file_from == -1 || read_bytes == -1)
		{
			fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		write_bytes = write(file_to, buffer, read_bytes);
		if (file_to == -1 || write_bytes == -1)
		{
			fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		read_bytes = read(file_from, buffer, 1024);
		file_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (read_bytes > 0);

	free(buffer);
	closeFile(file_from);
	closeFile(file_to);

	return (0);
}

