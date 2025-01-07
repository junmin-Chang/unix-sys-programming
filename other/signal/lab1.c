#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

int main(void) {
    int targetPID = 0;
    scanf("%d", &targetPID);
    while (1) {
        if (kill(targetPID, SIGKILL) == -1) {
                switch (errno) {
                    case EPERM:
                        printf("Not enough permission\n!");
                        break;
                    case ESRCH:
                        printf("Cannot find the proces %d\n", targetPID);
                        break;
                }
            } else {
                printf("Bang! -> %d\n", targetPID);
            }
    }
    
}