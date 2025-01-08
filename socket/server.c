//TCP 서버 프로그램
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>

#define SIZE sizeof(struct sockaddr_in)

void catcher(int sig);
int newsockfd;

int main(void) {
    int sockfd;
    //INADDR_ANY: localhost
    struct sockaddr_in server = { AF_INET, 7000, INADDR_ANY };
    char c;
    static struct sigaction act;

    act.sa_handler = catcher;
    sigfillset(&(act.sa_mask));
    sigaction(SIGPIPE, &act, NULL);

    // 트랜스포트 엔드포인트 구축
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket call failed");
        exit(1);
    }
    
    // bind
    if (bind(sockfd, (struct sockaddr *)&server, SIZE) == -1) {
        perror("bind fall failed");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen call failed");
        exit(1);
    }

    for (;;) {
        if ((newsockfd = accept(sockfd, NULL, NULL)) == -1) {
            perror("accept call failed");
            continue;
        }

        // 연결을 처리할 자식을 하나 낳는다.
        // 만일 자식이면 클라이언트와 정보를 주고받는다.
        if (fork() == 0) {
            while (recv(newsockfd, &c, 1, 0) > 0) {
                c = toupper(c);
                send(newsockfd, &c, 1, 0);
            }
            // 클라이언트가 연결을 끊으면 종료한다.
            close(newsockfd);
            exit(0);
        }
        close(newsockfd);
    }

}

void catcher(int sig) {
    close(newsockfd);
    exit(0);
}