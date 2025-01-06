#include <sys/types.h>
#include <signal.h>
#include <setjmp.h>
#include <stdio.h>

sigjmp_buf position;

int main(void) {
    static struct sigaction act;
    void goback(void);

    if (sigsetjmp(position, 1) == 0) {
        act.sa_handler = goback;
        sigaction(SIGINT, &act, NULL);
    }
    
    // domenu();

}

void goback(void) {
    fprintf(stderr, "\nInterrupted\n");
    siglongjmp(position, 1);
}