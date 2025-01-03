#include <unistd.h>

int main(void) {
    uid_t uid, euid;
    gid_t gid, egid;

    uid = getuid();
    euid = geteuid();

    gid = getgid();
    egid = getegid();

    return 0;
}