#include "smallsh.h"
#include <stdlib.h>

static char inpbuf[MAXBUF], tokbuf[2*MAXBUF],
	    *ptr = inpbuf, *tok = tokbuf; // token은 어휘단위

int inarg(char);
int runcommand(char **, int );

// print prompt, read 1 line
int userin(char *p) {
	int c, count;

	ptr = inpbuf;
	tok = tokbuf;

	printf("%s", p);

	count = 0;

	while (1) {
		if ((c = getchar()) == EOF)
			return EOF;
		if (count < MAXBUF)
			inpbuf[count++] = c;
		// enter 입력 시
		if (c == '\n' && count < MAXBUF) {
			inpbuf[count] = '\0';
			return count;
		}
		// 줄이 너무 길면 재시작
		if (c == '\n') {
			printf("smallsh: input line too long\n");
			count = 0;
			printf("%s", p);
		}	
	}

}

int gettok(char **outptr) {
	int type;

	// outptr 문자열을 tok로 지정
	*outptr = tok;

	// 토큰을 포함하고 있는 버퍼로부터 여백을 제거
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;

	// 토큰 포인터를 버퍼내의 첫 토큰으로 지정 
	*tok++ = *ptr;

	switch (*ptr++) {
		case '\n':
			type = EOL;
			break;
		case '&':
			type = AMPERSAND;
			break;
		case ';':
			type = SEMICOLON;
			break;
		default:
			type = ARG;

			while (inarg(*ptr))
				*tok++ = *ptr++;
	}

	*tok++ = '\0';

	return type;
}

static char special[] = {' ', '\t', '&', ';', '\n', '\0'};


int inarg(char c) {
	char *wrk;

	for (wrk = special; *wrk; wrk++) {
		if (c == *wrk)
			return 0;
	}

	return 1;
}

// command line 처리
int procline(void) {
	char *arg[MAXARG + 1];
	int toktype;
	int narg; // current number of argument 
	int type; // fore or background
	
	narg = 0;

	for (;;) { // 무한 루프
		switch (toktype = gettok(&arg[narg])) {
			case ARG:
				if (narg < MAXARG)
					narg++;
				break;
			case EOL:
			case SEMICOLON:
			case AMPERSAND:
				if (toktype == AMPERSAND)
					type = BACKGROUND;
				else
					type = FOREGROUND;
				
				if (narg != 0) {
					arg[narg] = NULL;
					runcommand(arg, type);
				}

				if (toktype == EOL)
					return -1;

				narg = 0;
				break;
		}
	}
}

int runcommand(char **cline, int where) {
	pid_t pid;
	int status;

	switch (pid = fork()) {
		case -1:
			perror("smallsh");
			return -1;
		case 0:
			execvp(*cline, cline);
			perror(*cline);
			exit(1);
	}

	// parent's code / BACKGROUND 시 처리
	if (where == BACKGROUND) {
		printf("[Process id %d]\n", pid);
		return 0;
	}

	// pid가 퇴장할 때까지 기다린다.
	if (waitpid(pid,&status, 0) == -1)
		return -1;
	else
		return status;
}

char *prompt = "Command> ";

int main(void) {
	while(userin(prompt) != EOF)
		procline();

}

