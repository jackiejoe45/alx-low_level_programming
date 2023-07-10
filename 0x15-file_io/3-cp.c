#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error - handles errors
 * @message: error message
 *
 * Description: This function prints an error message to stderr.
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "Error: %s\n", message);
}

/**
 * exit_error - exits errors
 * @code: error code
 * @message: error message
 *
 * Description: This function prints an error message and exits the program
 *              with the specified error code.
 */
void exit_error(int code, const char *message)
{
	print_error(message);
	exit(code);
}

/**
 * copy_file - copies the content of a file to another file
 * @file_from: path to the source file
 * @file_to: path to the destination file
 * Return: 0 on success, -1 on failure
 *
 * Description: This function reads the content of the source file and writes
 *              it to the destination file.
 */
int copy_file(const char *file_from, const char *file_to)
{
	int file_from_fd, file_to_fd;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	file_from_fd = open(file_from, O_RDONLY);
	if (file_from_fd == -1)
	{
		exit_error(98, strerror(errno));
	}
	file_to_fd = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file_to_fd == -1)
	{
		close(file_from_fd);
		return (-1);
	}

	while ((bytes_read = read(file_from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(file_from_fd);
			close(file_to_fd);
			return (-1);
		}
	}

	close(file_from_fd);
	close(file_to_fd);

	if (bytes_read == -1)
	{
		return (-1);
	}

	return (0);
}

/**
 * main - program that copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, or error code on failure
 *
 * Description: This is the entry point of the program. It validates the
 *              command-line arguments and calls the copy_file function
 *              to perform the file copying operation.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		exit_error(97, "Usage: cp file_from file_to");
	}

	if (copy_file(argv[1], argv[2]) != 0)
	{
		exit_error(99, strerror(errno));
	}

	return (0);
}

