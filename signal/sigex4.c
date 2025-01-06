#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// defined in other file
void g_exit(int s) {
    unlink("tempfile");
    fprintf(stderr, "Interrupted -- exiting\n");
    exit(1);
}

// main
extern void g_exit(int);

static struct sigaction act;
act.sa_handler = g_exit;
sigaction(SIGINT, &act, NULL);
