#include <stdio.h>
#include <ctype.h>

#define YES     1
#define NO      0
#define ANSWSZ  80

static char *pdefault = "Type 'y' for YES, 'n' for NO";
static char *error = "Unexpected response";

int yesno(char *prompt) {
    char buf[ANSWSZ], *p_use, *p;

    p_use = (prompt == NULL) ? pdefault : prompt;

    for (;;) {
        printf("%s > ", p_use);

        if (fgets(buf, ANSWSZ, stdin) == NULL) {
            return EOF;
        }

        for (p = buf; isspace(*p); p++);

        switch (*p) {
            case 'Y':
            case 'y':
                return YES;
            case 'N':
            case 'n':
                return NO;
            default:
                printf("\n%s\n", error);
        }
    }
}

int main(void) {
    int ans;

    ans = yesno("Do you want to continue");
    if (ans == YES) {
        puts("YES");
    } else if (ans == NO) {
        puts("NO");
    } else {
        puts("EOF");
    }

    return 0;
}