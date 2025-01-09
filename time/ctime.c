#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    time_t timeval;
    
    time(&timeval);
    printf("The time is %s\n", ctime(&timeval));
    exit(0);
}