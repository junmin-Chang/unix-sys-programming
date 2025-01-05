// exec 시 메모리 덮어씌움.
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("---> Before exec function\n");

    if (execlp("ls", "ls", "-a", (char *)NULL) == -1) {
        perror("execlp");
        exit(1);
    }

    printf("---> After exec function\n"); // 실행 x
}