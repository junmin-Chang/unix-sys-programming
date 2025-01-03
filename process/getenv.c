#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *env;
    
    env = getenv("PATH");
    printf("PATH: %s\n", env);
}