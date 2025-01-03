#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
	pid_t pid;

	switch (pid = fork()) {
		case -1:
			fatal("fork failed");
			break;
		case 0:
			// child's
			execl("/bin/ls", "ls", "-l", (char*)NULL);
			fatal("execl failed");
			break;
		default:
			wait((int*)0);
			printf("ls completed\n");
			
			exit(0);
	}

	return 0;
}

int fatal(char *s) {
	perror(s);
	exit(1);
}
