// waiting for signal
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signo) {
    psignal(signo, "Received signal: ");
}

int main(void) {
    sigset_t set;

    signal(SIGALRM, handler);

    sigfillset(&set);
    // alarm blocking 제외
    sigdelset(&set, SIGALRM);
    alarm(3);
    printf("wait...\n");
    sigsuspend(&set);

    return 0;
}