#include "main.h"
#define min(a, b) (((a) < (b)) ? (size_t)(a) : (size_t)(b))
/**
 * read_textfile - reads the text from a file and prints it to POSIX stdout
 * @filename: name of file
 * @letters: number of letters to print
 * Return: The number of letters printed or 0 if an error occurs.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n, nwritten, file_size;
	size_t nread;
	char buf[1024];

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	file_size = lseek(fd, 0, SEEK_END);
	if (file_size == -1)
	{
		close(fd);
		return (0);
	}
	lseek(fd, 0, SEEK_SET);
	nread = 0;
	while (nread < min(letters, (size_t)file_size))
	{
		n = read(fd, buf, sizeof(buf));
		if (n == -1)
		{
			close(fd);
			return (0);
		}
		if (n == 0)
			break;
		nwritten = write(STDOUT_FILENO, buf, n);
		if (nwritten == -1 || nwritten != n)
		{
			close(fd);
			return (0);
		}
		nread += n;
	}
	close(fd);
	return (nread);
}
