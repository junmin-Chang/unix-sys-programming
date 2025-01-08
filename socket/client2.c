// UDP 클라이언트 프로그램
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char c;

    struct sockaddr_in client = { AF_INET, INADDR_ANY, INADDR_ANY };

    // server remote address
    struct sockaddr_in server = { AF_INET, 7000 };
    server.sin_addr.s_addr = inet_addr("127.0.1.1");

    // transport endpoint
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        perror("socket call failed");
        exit(1);
    }

    // bind
    if (bind(sockfd, (struct sockaddr *)&client, SIZE) == -1) {
        perror("bind call failed");
        exit(1);
    }

    while (read(0, &c, 1) != 0) {
        if (sendto(sockfd, &c, 1, 0, &server, SIZE) == -1) {
            perror("client: sending");
            continue;
        }

        // 못받아도 계속 진행
        if (recv(sockfd, &c, 1, 0) == -1) {
            perror("client: receiving");
            continue;
        }

        write(1, &c, 1);
    }

}