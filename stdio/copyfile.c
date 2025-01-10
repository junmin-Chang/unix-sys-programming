#include <stdio.h>

int copyfile(const char *f1, const char *f2) {
    FILE *inf, *outf;
    int c;

    if ((inf = fopen(f1, "r")) == NULL) {
        return -1;
    }
    if ((outf = fopen(f2, "w")) == NULL) {
        fclose(inf);
        return -1;
    }

    while ((c = getc(inf)) != EOF) {
        putc(c, outf);
    }

    fclose(inf);
    fclose(outf);

    return 0;
}

int main(void) {
    if (copyfile("indata", "outdata") == -1) {
        perror("Could not copy file");
        return 1;
    }

    return 0;
}