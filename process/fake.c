#include <stdlib.h>
#include <stdio.h>

void fake(int c) {
	exit(c);
}


int main(void) {
	fake(1);
	printf("not executed\n");
}

