#include <fcntl.h>
#include <stdio.h>

int filestatus(int fd) {
    int arg1;

    if ((arg1 = fcntl(fd, F_GETFL)) == -1) {
        printf("filestatus failed");
        return -1;
    }
    printf("fd: %d: ", fd);

    switch (arg1 & O_ACCMODE) {
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read write");
            break;
        case O_RDONLY:
            printf("read only");
            break;
        default:
            printf("No such mode");
    }
    
    if (arg1 & O_APPEND) {
        printf(" -append flag set");
    }
    printf("\n");

    return 0;
}

int main(void) {
    int fd;

    if ((fd = open("test1", O_WRONLY | O_APPEND)) == -1) {
        printf("open failed");
        return 1;
    }

    filestatus(fd);

    close(fd);

    return 0;
}