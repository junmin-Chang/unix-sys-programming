// UDP 서버 프로그램
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char c;

    struct sockaddr_in server = { AF_INET, 7000, INADDR_ANY };
    struct sockaddr_in client;
    int client_len = SIZE;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket call failed");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&server, SIZE) == -1) {
        perror("bind call failed");
        exit(1);
    }
    
    for (;;) {
        if (recvfrom(sockfd, &c, 1, 0, &client, &client_len) == -1) {
            perror("server: receiving");
            continue;
        }

        c = toupper(c);

        if (sendto(sockfd, &c, 1, 0, &client, client_len) == -1) {
            perror("server: sending");
            continue;
        }
    }
}