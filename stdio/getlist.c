#include <stdio.h>
#include <string.h>

#define MAXLEN 255
#define MAXCMD 100
#define ERROR -1
#define SUCCESS 0

int getlist(char *namepart, char dirnames[][MAXLEN + 1], int maxnames) {
    char cmd[MAXCMD + 1];
    char in_line[MAXLEN + 2];

    int i;
    FILE *lsf;

    strcpy(cmd, "ls ");

    if (namepart != NULL) 
        strncat(cmd, namepart, MAXCMD - strlen(cmd));

    if ((lsf = popen(cmd, "r")) == NULL)
        return ERROR;
    
    for (i = 0; i < maxnames; i++) {
        if (fgets(in_line, MAXLEN + 2, lsf) == NULL) 
            break;
        
        if (in_line[strlen(in_line) - 1] == '\n') 
            in_line[strlen(in_line) -1] = '\0';
        
        strcpy(&dirnames[i][0], in_line);
    }

    if (i < maxnames) 
        dirnames[i][0] = '\0';
    
    pclose(lsf);
    return SUCCESS;
}

int main(void) {
    char namebuf[100][MAXLEN + 1];
    int i;

    if (getlist("*.c", namebuf, 100) == ERROR) {
        perror("Could not get list");
        return 1;
    }

    for (i = 0; namebuf[i][0] != '\0'; i++) {
        puts(namebuf[i]);
    }

    return 0;
}