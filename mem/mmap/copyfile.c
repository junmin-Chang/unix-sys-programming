#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
    int input, output;
    size_t filesize;
    void *source, *target;
    char endchar = '\0';

    if (argc != 3) {
        fprintf(stderr, "usage: copyfile source target\n");
        exit(1);
    }

    if ((input = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }

    if ((output = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1) {
        close(input);
        fprintf(stderr, "Error opening file %s\n", argv[2]);
        exit(2);
    }

    filesize = lseek(input, 0, SEEK_END);
    lseek(output, filesize - 1, SEEK_SET);
    write(output, &endchar, 1);

    if ((source = mmap(0, filesize, PROT_READ, MAP_SHARED, input, 0)) == (void *)-1) {
        fprintf(stderr, "Error mapping first file\n");
        exit(1);
    }

    if ((target = mmap(0, filesize, PROT_WRITE, MAP_SHARED, output, 0)) == (void *)-1) {
        fprintf(stderr, "Error mapping second file\n");
        exit(2);
    }

    memcpy(target, source, filesize);
    
    munmap(source, filesize);
    munmap(target, filesize);

    close(input);
    close(output);

    exit(0);
}