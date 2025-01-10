#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZ 63

char *fifo = "fifo";

int main(int argc, char **argv) {
    int fatal(char *);
    int fd;
    char msgbuf[MSGSIZ + 1];

    if (mkfifo(fifo, 0666) == -1) {
        if (errno != EEXIST) 
            fatal("receiver: mkfifo");
    }

    if ((fd = open(fifo, O_RDWR)) < 0) 
        fatal("fifo open failed");
    
    for (;;) {
        if (read(fd, msgbuf, MSGSIZ + 1) < 0)
            fatal("message read failed");

        printf("message received: %s\n", msgbuf);
    }
}

int fatal(char *s) {
    perror(s);
    exit(1);
}