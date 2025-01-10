#include <stdio.h>

char *inname = "indata";
char *outname = "outdata";

int main(void) {
    int fatal(char *);
    FILE *inf, *outf;

    if ((inf = fopen(inname, "r")) == NULL) 
        fatal("Could not open input file");
    if ((outf = fopen(outname, "w")) == NULL)
        fatal("Could not open output file");
    
    // do something

    fclose(inf);
    fclose(outf);

    exit(0);
}

int fatal(char *s) {
    perror(s);
    exit(1);
}