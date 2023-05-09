#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>


/**
 * display_error - display error message on stderr
 * @msg: error message to display
 */
void display_error(char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
}

/**
 * read_elf_header - read ELF header from file descriptor into buffer
 * @fd: file descriptor of ELF file
 * @header: pointer to buffer to store ELF header
 */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
	if (read(fd, header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		perror("Error reading ELF header");
		exit(EXIT_FAILURE);
	}
	if (memcmp(header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Invalid ELF magic number\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * print_elf_header - print contents of ELF header to stdout
 * @header: pointer to buffer containing ELF header
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	if (header->e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("  Class:                             ELF64\n");
	} else
	{
		printf("  Class:                             ELF32\n");
	}
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("  Data:                              2's complement, little endian\n");
	} else
	{
		printf("  Data:                              2's complement, big endian\n");
	}
	printf("  Version:                           %d\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %d\n", header->e_type);
	printf("  Machine:                           %d\n", header->e_machine);
	printf("  Version:                           %d\n", header->e_version);
	printf("  Entry point address:               0x%lx\n", header->e_entry);
	printf("  Start of program headers:          %ld (bytes in file)\n", header->e_phoff);
	printf("  Start of section headers:          %ld (bytes in file)\n", header->e_shoff);
	printf("  Flags:                             0x%x\n", header->e_flags);
	printf("  Size of this header:               %d (bytes)\n", header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", header->e_phentsize);
	printf("  Number of program headers:         %d\n", header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", header->e_shentsize);
	printf("  Number of section headers:         %d\n", header->e_shnum);
	printf("  Section header string table index: %d\n", header->e_shstrndx);
}

/**
 * format_magic - format the ELF magic number as a string
 * @buf: buffer to store formatted string
 * @magic: pointer to buffer containing the ELF magic number
 */
void format_magic(char *buf, unsigned char *magic)
{
	sprintf(buf, "%02x %02x %02x %02x", magic[0], magic[1], magic[2], magic[3]);
}

/**
 * main - entry point of the program
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 if successful, 98 if error occurred
 */
int main(int argc, char *argv[])
{
	char  *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	Elf64_Ehdr elf_header;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (98);
	}
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
		return (98);
	}
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		fprintf(stderr, "Error: Cannot read ELF header from file '%s'\n", filename);
		close(fd);
		return (98);
	}
	print_elf_header(&elf_header);
	close(fd);
	return (0);
}
