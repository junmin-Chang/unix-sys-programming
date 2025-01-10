#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define LINESZ 50
#define SUCCESS 0
#define ERROR -1

int dokill(pid_t , const char *, const char *);
    

int main(int argc, char **argv) {
    // 이들의 초기화는 당신의 시스템에 좌우된다.
    static char *pspart = "ps -t";
    static char *fmt = "%d %*s %*s %s";

    char comline[LINESZ], inbuf[LINESZ], header[LINESZ];
    char name[LINESZ];
    FILE *f;
    int killflag = 0, j;
    pid_t pid;

    if (argc <= 2) {
        fprintf(stderr, "Usage: %s tty program ...\n", argv[0]);
        exit(1);
    }

    strcpy(comline, pspart);
    strcat(comline, argv[1]);

    if ((f = popen(comline, "r")) == NULL) {
        fprintf(stderr, "%s:could not run ps program\n", argv[0]);
        exit(3);
    }

    if (fgets(header, LINESZ, f) == NULL) {
        fprintf(stderr, "%s:no output from ps?\n", argv[0]);
        exit(3);
    }

    while (fgets(inbuf, LINESZ, f) != NULL) {
        if (sscanf(inbuf, fmt, &pid, name) < 2) 
            break;
        /* 
        0: ps 
        1: -t
        2: tty
        3: program
        */
        for (j = 2; j < argc; j++) {
            if (strcmp(name, argv[j]) == 0) {
                if (dokill(pid, inbuf, header) == SUCCESS) 
                    killflag++;
            }
        }
    }

    // 이것은 오류가 아니라 경고다.
    if (!killflag) {
        fprintf(stderr, "%s: no program killed on %s\n", argv[0], argv[1]);
    }

    exit(0);
}

int dokill(pid_t procid, const char *line, const char *hd) {
    char c;

    printf("\nProcess running named program found: \n");
    printf("\t%s\t%s\n", hd, line);
    printf("Type 'y' to kill process %d\n", procid);
    printf("\nAnswer > ");

    scanf("%ls", &c);

    if (c == 'y' || c == 'Y') {
        kill(procid, SIGKILL);
        return SUCCESS;
    }

    return ERROR;
}