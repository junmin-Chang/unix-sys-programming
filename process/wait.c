


...

int status;
pid_t cpid;

cpid = fork();

if (cpid == 0) {
	// do something (child)
} else {
	cpid = wait(&status);
	printf("The child %d is dead\n", cpid);

}
