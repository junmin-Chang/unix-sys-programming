#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *argv[2], *envp[3];

    argv[0] = "showmyenv";
    argv[1] = NULL;

    envp[0] = "foo=bar";
    envp[1] = "bar=foo";
    envp[2] = NULL;

    execve("./showmyenv", argv, envp);

    perror("execve failed");
}