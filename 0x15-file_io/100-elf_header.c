#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 64

/**
  *  print_error - prints the error
  *  @message: error message
  */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
  * print_elf_header - prints the elf header
  * @fd: filee descriptor
  */
void print_elf_header(int fd)
{
	unsigned char buf[BUF_SIZE];
	int i;

	if (read(fd, buf, sizeof(buf)) != sizeof(buf))
		print_error("Failed to read ELF header");

	if (memcmp(buf, "\x7f ELF", 4) != 0)
		print_error("Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", buf[i]);
	printf("\n");

	printf("  Class:                             ");
	switch (buf[4])
	{
		case 1:
			printf("ELF32\n");
			break;
		case 2:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Data:                              ");
	switch (buf[5])
	{
		case 1:
			printf("2's complement, little endian\n");
			break;
		case 2:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Version:                           %d (current)\n", buf[6]);

	printf("  OS/ABI:                            ");
	switch (buf[7])
	{
		case 0:
			printf("UNIX - System V\n");
			break;
		case 1:
			printf("HP-UX\n");
			break;
		case 2:
			printf("NetBSD\n");
			break;
		case 3:
			printf("Linux\n");
			break;
		case 6:
			printf("Sun Solaris\n");
			break;
		case 9:
			printf("FreeBSD\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  ABI Version:                       %d\n", buf[8]);

	printf("  Type:                              ");
	switch (*(unsigned short *)(buf + 16))
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Entry point address:               0x");
	for (i = 0; i < 8; i++)
		printf("%02x", buf[24 + i]);
	printf("\n");
}

/**
  * main - Entry point
  * @argc: number of arguments
  * @argv: arguments
  * Return: Always 0
  */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;

		if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	filename = argv[1];

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Failed to open file");
	}

	print_elf_header(fd);

	close(fd);
	return (0);
}
