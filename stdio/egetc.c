#include <stdio.h>

int egetc(FILE *stream) {
    int c;

    c = getc(stream);
    if (c == EOF) {
        // 에러인지 EOF 인지 check
        if (ferror(stream)) {
            fprintf(stderr, "fatal error: input error\n");
            exit(1);
        } else {
            fprintf(stderr, "warning: EOF\n");
        }
    }

    return c;
}