#include <stdio.h>
#include <unistd.h>
const char bel = 0x07;

void warnuser(const char *string) {
    if (isatty(fileno(stderr))) {
        fprintf(stderr, "%c%c%c", bel, bel, bel);
    }
    fprintf(stderr, "%s\n", string);
    
} 

int main(void) {
    warnuser("Warning");

    return 0;
}