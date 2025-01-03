// shell 명령 수행

#include <unistd.h>
#include <stdlib.h>

int docommand(char *command) {
	pid_t pid;
	
	if ((pid = fork()) < 0)
		return -1;

	if (pid == 0) {
		//child
		execl("/bin/sh", "sh", "-c", command, (char*)NULL);
		perror("execl");
		exit(1);
	}

	// parent's
	wait((int*)0);
	
	return 0;

}
