#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int fd1, fd2;
fd_set readset;

fd1 = open("file1", O_RDONLY);
fd2 = open("file2", O_RDONLY);

FD_ZERO(&readset);
FD_SET(fd1, &readset);
FD_SET(fd2, &readset);

switch (select(5, &readset, NULL, NULL, NULL)) {
    //logic
}
