#include <ctype.h>
#include <stdio.h>

#define MAXTOK 256

static char inbuf[MAXTOK + 1];

char *getword(FILE *inf) {
    int c, count = 0;

    do {
        c = getc(inf);
    } while (isspace(c));

    if (c == EOF) 
        return NULL;
    
    if (!isalnum(c)) {
        inbuf[count++] = c;
    } else {
        do {
            if (count < MAXTOK) 
                inbuf[count++] = c;
            c = getc(inf);
        } while (isalnum(c));

        ungetc(c, inf);
    }
    inbuf[count] = '\0';

    return inbuf;
}

int main(void) {
    char *p;
    FILE *inf;

    if ((inf = fopen("indata", "r")) == NULL) {
        perror("Could not open input file");
        return 1;
    }

    while ((p = getword(inf)) != NULL) {
        puts(p);
    }

    fclose(inf);

    return 0;
}