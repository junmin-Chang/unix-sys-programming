// blocking signals

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handler_SIGINT(int _signo) {
    printf("Received signal : %s\n", strsignal(_signo));
}

int main(void) {
    sigset_t new;

    if (signal(SIGINT, handler_SIGINT) == SIG_ERR) {
        perror("signal SIGINT"); 
        exit(1);
    }

    sigemptyset(&new);
    sigaddset(&new, SIGINT);
    sigaddset(&new, SIGQUIT);
    sigprocmask(SIG_BLOCK, &new, (sigset_t *)NULL);

    sleep(5);
    printf("Unblocking signals\n");
    sigprocmask(SIG_UNBLOCK, &new, (sigset_t *)NULL);

    return 0;
}