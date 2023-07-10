#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

/**
  * print_usage_and_exit - as it says
  */
void print_usage_and_exit(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
  * open_file - opens the file with flags and mode
  * @filename: name of file
  * @flags: flags
  * @mode: mode to open file
  * Return: file descriptor
  */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
  * copy_file - copies a files
  * @from_filename: source
  * @to_filename: destination
  */
void copy_file(const char *from_filename, const char *to_filename)
{
	int fd_from = open_file(from_filename, O_RDONLY, O_RDONLY);
	int fd_to = open_file(to_filename, O_WRONLY | O_CREAT | O_TRUNC, 664);

	char buf[BUF_SIZE];
	ssize_t n_read, n_written;

	while ((n_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		n_written = write(fd_to, buf, n_read);
		if (n_written != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Failed to write to file %s\n", to_filename);
			exit(99);
		}
	}

	if (n_read < 0)
	{
		dprintf(STDERR_FILENO, "Error:Failed to read from file %s\n", from_filename);
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file %s\n", from_filename);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close file %s\n", to_filename);
		exit(100);
	}
}

/**
 * main - program that copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, or error code on failure
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		print_usage_and_exit();
	}
	copy_file(argv[1], argv[2]);
	return (0);
}

