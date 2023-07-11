#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define EI_NIDENT 16

/**
 * Elf64_Ehdr - ELF Header structure
 *
 * @e_ident: ELF identification bytes
 * @e_type: Object file type
 * @e_machine: Architecture of the file
 * @e_version: Version of the object file format
 * @e_entry: Virtual address to which the system first transfers control
 * @e_phoff: Program header table's file offset in bytes
 * @e_shoff: Section header table's file offset in bytes
 * @e_flags: Processor-specific flags
 * @e_ehsize: ELF header's size in bytes
 * @e_phentsize: Size in bytes of one entry in the program header table
 * @e_phnum: Number of entries in the program header table
 * @e_shentsize: Size in bytes of one entry in the section header table
 * @e_shnum: Number of entries in the section header table
 * @e_shstrndx: Index of the section header table entry that contains the section names
 */
typedef struct
{
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;
/**
 * display_elf_header - Display the information contained in the struct
 * @elf_header: Pointer to the ELF header struct
 */
void display_elf_header(const Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", elf_header->e_ident[i]); }
	printf("\n");
	printf("  Class:                             ");
	if (elf_header->e_ident[4] == 1)
	{
		printf("ELF32\n"); }
	else if (elf_header->e_ident[4] == 2)
	{
		printf("ELF64\n"); }
	else
	{
		printf("Invalid\n");
		exit(98); }
	printf("  Data:                              ");
	if (elf_header->e_ident[5] == 1)
	{
		printf("2's complement, little endian\n"); }
	else if (elf_header->e_ident[5] == 2)
	{
		printf("2's complement, big endian\n"); }
	else
	{
		printf("Invalid\n");
		exit(98); }
	printf("  Version:                       %u (current)\n", elf_header->e_ident[6]);
	printf("  OS/ABI:                            ");
	switch (elf_header->e_ident[7])
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
		case 4:
			printf("GNU Hurd\n");
			break;
		case 6:
			printf("Solaris\n");
			break;
		case 7:
			printf("AIX\n");
			break;
		case 8:
			printf("IRIX\n");
			break;
		case 9:
			printf("FreeBSD\n");
			break;
		case 10:
			printf("Tru64\n");
			break;
		case 11:
			printf("Novell Modesto\n");
			break;
		case 12:
			printf("OpenBSD\n");
			break;
		case 13:
			printf("OpenVMS\n");
			break;
		case 14:
			printf("NonStop Kernel\n");
			break;
		case 15:
			printf("AROS\n");
			break;
		case 16:
			printf("Fenix OS\n");
			break;
		case 17:
			printf("CloudABI\n");
			break;
		case 18:
			printf("OpenVOS\n");
			break;
		default:
			printf("<unknown: %u>\n", elf_header->e_ident[7]);
			break; }
	printf("  ABI Version:                       %u\n", elf_header->e_ident[8]);
	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
		case 0:
			printf("NONE (No file type)\n");
			break;
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown\n");
			exit(98); }
	printf("  Entry point address:               0x%lx\n", elf_header->e_entry); }

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98); }
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Unable to open file '%s'\n", argv[1]);
		exit(98); }

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		fprintf(stderr, "Error: Unable to read ELF header from file '%s'\n", argv[1]);
		close(fd);
		exit(98); }
	display_elf_header(&elf_header);
	close(fd);
	return (0); }

