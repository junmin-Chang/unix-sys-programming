#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(void) {
    int fd;

    if ((fd = open("nonexist", O_RDONLY)) == -1) {
        fprintf(stderr, "error: %d\n", errno);
    }

    return 0;
}