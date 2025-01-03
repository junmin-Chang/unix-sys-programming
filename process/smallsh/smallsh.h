#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define EOL		1 // end of line
#define ARG		2 // normal argument
#define AMPERSAND	3
#define SEMICOLON	4

#define MAXARG		512
#define MAXBUF		512

#define FOREGROUND	0
#define BACKGROUND	1	
