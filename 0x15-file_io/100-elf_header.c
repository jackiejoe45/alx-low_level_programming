#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUF_SIZE 64

/**
 * print_error - prints the error
 * @message: error message
 */
void print_error(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(98);
}

const char *get_elf_osabi(unsigned char osabi)
{
    switch (osabi) 
    {
        case ELFOSABI_SYSV: return "UNIX - System V";
        case ELFOSABI_NETBSD: return "UNIX - NetBSD";
        case ELFOSABI_SOLARIS: return "UNIX - Solaris";
        default: return "Unknown";
    }
}

/**
 * print_elf_header - prints the elf header
 * @fd: file descriptor
 */
void print_elf_header(int fd) {
    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header)) {
        print_error("Failed to read ELF header");
    }

    if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < SELFMAG; i++) {
        printf("%02x ", header.e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", get_elf_class(header.e_ident[EI_CLASS]));
    printf("  Data:                              %s\n", get_elf_data(header.e_ident[EI_DATA]));
    printf("  Version:                           %d\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", get_elf_osabi(header.e_ident[EI_OSABI]));
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", get_elf_type(header.e_type));
    printf("  Machine:                           %s\n", get_elf_machine(header.e_machine));
    printf("  Version:                           %d\n", header.e_version);
    printf("  Entry point address:               %p\n", (void *)header.e_entry);
    printf("  Start of program headers:          %lu (bytes in file)\n", header.e_phoff);
    printf("  Start of section headers:          %lu (bytes in file)\n", header.e_shoff);
    printf("  Flags:                             0x%lx\n", header.e_flags);
    printf("  Size of this header:               %d (bytes)\n", header.e_ehsize);
    printf("  Size of program headers:           %d (bytes)\n", header.e_phentsize);
    printf("  Number of program headers:         %d\n", header.e_phnum);
    printf("  Size of section headers:           %d (bytes)\n", header.e_shentsize);
    printf("  Number of section headers:         %d\n", header.e_shnum);
    printf("  Section header string table index: %d\n", header.e_shstrndx);
}

/** main - Entry point
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

