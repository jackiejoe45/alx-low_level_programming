#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFFER_SIZE 1024

void error(char *message);

int main(int argc, char **argv)
{
	int source_fd, destination_fd;
	Elf32_Ehdr header;
	int i;

	if (argc != 3)
	{
		error("Usage: elf_header <source_file> <destination_file>\n");
	}

	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		error("Error: Can't open source file\n");
	}
	destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (destination_fd == -1)
	{
		error("Error: Can't open destination file\n");
	}
	if (read(source_fd, &header, sizeof(header)) != sizeof(header))
	{
		error("Error: Can't read ELF header\n");
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\n");
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("invalid\n");
			break;
	}
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("invalid\n");
			break;
	}
	printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - GNU/Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("unknown\n");
			break;
	}
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header.e_type)
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
			printf("unknown\n");
			break;
	}
	printf("  Machine:                           ");
	switch (header.e_machine)
	{
		case EM_NONE:
			printf("No machine\n");
			break;
		case EM_M32:
			printf("AT&T WE 32100\n");
			break;
		case EM_SPARC:
			printf("SPARC\n");
			break;
		case EM_386:
			printf("Intel 80386\n");
			break;
		case EM_68K:
			printf("Motorola 68000\n");
			break;
		case EM_88K:
			printf("Motorola 88000\n");
			break;
		case EM_860:
			printf("Intel 80860\n");
			break;
		case EM_MIPS:
			printf("MIPS RS3000 Big-Endian\n");
			break;
		case EM_ARM:
			printf("ARM\n");
			break;
		case EM_X86_64:
			printf("Advanced Micro Devices X86-64\n");
			break;
		case EM_AARCH64:
			printf("AArch64 (64-bit ARM)\n");
			break;
		default:
			printf("Unknown machine\n");
			break;
	}
	printf("  Version:                           %d (current)\n", header.e_version);
	printf("  Entry point address:               0x%x\n", header.e_entry);
	printf("  Start of program headers:          %d (bytes into file)\n", header.e_phoff);
	printf("  Start of section headers:          %d (bytes into file)\n", header.e_shoff);
	printf("  Flags:                             0x%x\n", header.e_flags);
	printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);
	printf("  Size of program headers:            %d (bytes)\n", header.e_phentsize);
	printf("  Number of program headers:         %d\n", header.e_phnum);
	printf("  Size of section headers:            %d (bytes)\n", header.e_shentsize);
	printf("  Number of section headers:         %d\n", header.e_shnum);
	printf("  Section header string table index: %d\n", header.e_shstrndx);

	close(source_fd);
	close(destination_fd);

	return (0);
}

void error(char *message)
{
	printf("%s", message);
	exit(1);
}
