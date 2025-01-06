#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int ntimes = 0;

int main(void) {
    pid_t pid, ppid;
    void p_action(int), c_action(int);
    static struct sigaction pact, cact;

    // 부모를 위해 SIGUSR1 action 지정
    pact.sa_handler = p_action;
    sigaction(SIGUSR1, &pact, NULL);

    switch (pid = fork()) {
        case -1:
            perror("synchro");
            exit(1);
        case 0:
            cact.sa_handler = c_action;
            sigaction(SIGUSR1, &cact, NULL);

            ppid = getppid();

            for (;;) {
                sleep(1);
                kill(ppid, SIGUSR1);
                pause();
            }
        default:
            for (;;) {
                pause();
                sleep(1);
                kill(pid, SIGUSR1);
            }
    }
}

void p_action(int sig) {
    printf("Parent caught signal #%d\n", ++ntimes);
}

void c_action(int sig) {
    printf("Child caught signal #%d\n", ++ntimes);
}