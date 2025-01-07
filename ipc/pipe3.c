#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

int main(void) {
    char inbuf[MSGSIZE];
    int p[2], j;
    pid_t pid;

    if (pipe(p) == -1) {
        perror("pipe call");
        exit(1);
    }

    switch (pid = fork()) {
        case -1:
            perror("fork call");
            exit(2);
            break;
        case 0:
            // 자식이면 읽기 닫고, 쓰기만해라
            close(p[0]);
            write(p[1], msg1, MSGSIZE);
            write(p[1], msg2, MSGSIZE);
            write(p[1], msg3, MSGSIZE);
            break;
        default:
            // 부모면 읽기만해라
            close(p[1]);
            for (j = 0; j < 3; j++) {
                read(p[0], inbuf, MSGSIZE);
                printf("%s\n", inbuf);
            }
            wait(NULL);
    }
    exit(0);
}