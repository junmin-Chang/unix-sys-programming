// TCP 클라이언트 프로그램
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SIZE sizeof(struct sockaddr_in)

int main(void) {
    int sockfd;
    char c, rc;
    struct sockaddr_in server = { AF_INET, 7000 };

    server.sin_addr.s_addr = inet_addr("127.0.1.1");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket call failed");
        exit(1);
    }

    if ((connect(sockfd, (struct sockaddr *)&server, SIZE)) == -1) {
        perror("connect call failed");
        exit(1);
    }

    // 서버로부터 데이터를 읽어들인다.
    for (rc = '\n';;) {
        if (rc == '\n') 
            printf("Input a lower case character: ");
        c = getchar();
        send(sockfd, &c, 1, 0);
        if (recv(sockfd, &rc, 1, 0) > 0) {
            printf("%c", rc);
        } else {
            printf("server has died\n");
            close(sockfd);
            exit(1);
        }
    } 
}