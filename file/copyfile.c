#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512
#define PERM 0644

int copyfile(const char *name1, const char *name2) {
    int infile, outfile;
    ssize_t nread;
    char buffer[BUFSIZE];

    if ((infile = open(name1, O_RDONLY)) == -1) {
        return -1;
    }

    if ((outfile = open(name2, O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1) {
        close(infile);
        return -2;
    }

    while ((nread = read(infile, buffer, BUFSIZE)) > 0) {
        if (write(outfile, buffer, nread) < nread) {
            close(infile);
            close (outfile);
            return -3;
        }
    }

    close(infile);
    close(outfile);

    if (nread == -1) {
        return -4;
    } else {
        return 0;
    }
}

int main(void) {
    if (copyfile("test1", "test2") < 0) {
        return 1;
    }

    return 0;
}