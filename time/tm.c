#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    time_t t;
    struct tm *tp;

    // from system, get time    
    time(&t);

    tp = localtime(&t);

    printf("Time %d:%d:%d\n", tp->tm_hour, tp->tm_min, tp->tm_sec);

    exit(0);
}