#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int infile, outfile;
	char buf[BUFSIZ];
 	int nread = 0;

	if ((infile = open("test.txt", O_RDONLY, 0644)) == -1) {
		perror("open");
		exit(1);
	}
	if ((outfile = open("out.txt", O_WRONLY | O_CREAT, 0644)) == -1) {
		perror("open");
		exit(1);
	}

	while ((nread = read(infile, buf, BUFSIZ)) > 0) {
		if (write(outfile, buf, nread) < nread) {
			close(infile);
			close(outfile);
			exit(1);
		}
	}

	close(infile);
	close(outfile);

	if (nread == -1)
		return -4;
	else
		return 0;

	return 0;

}
