// 파이프 크기 제한
#include <signal.h>
#include <unistd.h>
#include <limits.h>

int count;
void alrm_action(int);

int main(void) {
    int p[2];
    int pipe_size;
    char c = 'x';
    static struct sigaction act;

    act.sa_handler = alrm_action;
    sigfillset(&(act.sa_mask));

    if (pipe(p) == -1) {
        perror("pipe call");
        exit(1);
    }

    // 크기 set
    pipe_size = fpathconf(p[0], _PC_PIPE_BUF);
    printf("Maximum size of write to pipe : %dbytes\n", pipe_size);

    sigaction(SIGALRM, &act, NULL);

    while (1) {
        alarm(20);
        write(p[1], &c, 1);
        alarm(0);

        if ((++count % 1024) == 0) {
            printf("%d characters in pipe\n", count);
        }
    }
}

void alrm_action(int signo) {
    printf("write blocked after %d characters\n", count);
    exit(0);
}