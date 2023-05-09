#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <elf.h>

/**
 * print_error - returns error mssge
 * @msg: type of error
 */
void print_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header - as it says
 * @filename: name of file
 */
void print_elf_header(char *filename)
{
	int fd, ret, i;
	Elf64_Ehdr ehdr;
	char magic[5];

	memset(&ehdr, 0, sizeof(ehdr));

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error("Could not open file");
	}
	ret = read(fd, &ehdr, sizeof(ehdr));
	if (ret < 0)
	{
		print_error("Could not read ELF header");
	}
	memcpy(magic, ehdr.e_ident, 4);
	magic[4] = '\0';
	if (strcmp(magic, ELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ehdr.e_ident[i]);
	}
	printf("\n");
	if (ehdr.e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("  Class:                           ELF32\n");
	}
	else
	{
		printf("  Class:                           ELF64\n");
	}
	close(fd);
}

/**
 * print_elf_header_cont - continued
 * @filename: name of file
 */
void print_elf_header_cont(char *filename)
{
	int fd;
	Elf64_Ehdr ehdr;

	memset(&ehdr, 0, sizeof(ehdr));
	fd = open(filename, O_RDONLY);

	if (ehdr.e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("  Data:                            2's complement, little endian\n");
	}
	else
	{
		printf("  Data:                            2's complement, big endian\n");
	}
	printf("  Version:                        %d\n", ehdr.e_ident[EI_VERSION]);
	printf("  OS/ABI:                          ");
	switch (ehdr.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
	printf("  ABI Version:                  %d\n", ehdr.e_ident[EI_ABIVERSION]);
	printf("  Type:                            ");
	close(fd);
}
/**
 * print_elf_header_cont_2 - continued
 * @filename: name of file
 */
void print_elf_header_cont_2(char *filename)
{
	int fd;
	Elf64_Ehdr ehdr;

	memset(&ehdr, 0, sizeof(ehdr));
	fd = open(filename, O_RDONLY);

	switch (ehdr.e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>\n");
			break;
	}
	printf("  Entry point address:             %p\n", (void *)ehdr.e_entry);
	close(fd);
}

/**
 * main - entry point
 * @argc: number of params
 * @argv: parameters
 * Return: 0(Success)
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}
	print_elf_header(argv[1]);
	print_elf_header_cont(argv[1]);
	print_elf_header_cont_2(argv[1]);
	return (0);
}
