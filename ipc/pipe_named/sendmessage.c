#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZ 63

char *fifo = "fifo";

int main(int argc, char **argv) {
    int fatal(char *);
    int fd, j, nwrite;
    char msgbuf[MSGSIZ + 1];

    if (argc < 2) {
        fprintf(stderr, "Usage: sendmessage msg...\n");
        exit(1);
    }

    // O_NONBLOCK을 설정하여 fifo를 열기 
    if ((fd = open(fifo, O_WRONLY | O_NONBLOCK)) < 0) 
        fatal("fifo open failed");
    
    // message 전송
    for (j = 1; j < argc; j++) {
        if (strlen(argv[j]) > MSGSIZ) {
            fprintf(stderr, "message too long %s\n", argv[j]);
            continue;
        }

        strcpy(msgbuf, argv[j]);

        if ((nwrite = write(fd, msgbuf, MSGSIZ+1)) == -1) 
            fatal("message write failed");
    }

    exit(0);
}

int fatal(char *s) {
    perror(s);
    exit(1);
}