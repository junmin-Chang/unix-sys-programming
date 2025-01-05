#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    pid_t pid;

    switch (pid = fork()) {
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("Child process - PID: %d, PPID: %d\n", (int)getpid(), (int)getppid());
            break;
        default:
            printf("Parent process - PID: %d, PPID: %d, Child PID: %d\n",
            (int)getpid(), (int)getppid(), (int)pid);
            break;
    }

    printf("End of fork\n"); // 2번 출력됨.

    return 0;
}