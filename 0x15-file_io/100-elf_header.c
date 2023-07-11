#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>

#define BUF_SIZE 128

/*
 * print_error - Prints an error message.
 * @msg: message
 * Return: none
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/*
 * print_elf_header - Prints the ELF header information.
 * @header: header
 * Return: none
 */
void print_elf_header(const Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");

	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown>\n");
	}

	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("<unknown: %d>\n", ELFOSABI_NONE);
			break;
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
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
	}

	printf("  Entry point address:               0x%lx\n", header->e_entry);
}

/*
 * read_elf_header - Opens the ELF file and reads the ELF header.
 * @filename: file name
 * @header: header
 * Return: none
 */
void read_elf_header(const char *filename, Elf64_Ehdr *header)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		print_error("Error opening file");
	}

	ssize_t bytes_read = read(fd, header, sizeof(*header));

	if (bytes_read == -1)
	{
		print_error("Error reading file");
	}

	if (bytes_read != sizeof(*header))
	{
		print_error("Incomplete ELF header");
	}

	if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
	}

	close(fd);
}

/*
 * main - entry point
 * @argc: number of characters
 * @argv: array of characters
 * Return: Zero
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	Elf64_Ehdr header;

	read_elf_header(argv[1], &header);
	print_elf_header(&header);

	return (0);
}
