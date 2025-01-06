#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
    static struct sigaction act; 
    static struct sigaction oact;

    // catchint 선언. 후에 handler로 쓰임.
    void catchint(int signo);
    
    // oact에 default action을 저장?
    sigaction(SIGINT, NULL, &oact);
    // act의 sa_handler에 catchint를 넣음.
    act.sa_handler = SIG_IGN;

    sigfillset(&(act.sa_mask));

    // sigaction 호출 전에는, SIGINT의 기본 동작은 종료임.
    sigaction(SIGINT, &act, NULL);

    // SIGINT를 수신하면, 제어가 catchint로 넘어감

    printf("sleep call #1\n");
    sleep(1);
    printf("sleep call #2\n");
    sleep(1);
    printf("sleep call #3\n");
    sleep(1);
    printf("sleep call #4\n");
    sleep(1);

    // 과거 행동(default action) 복원
    sigaction(SIGINT, &oact, NULL);

       printf("sleep call #1\n");
    sleep(1);
    printf("sleep call #2\n");
    sleep(1);
    printf("sleep call #3\n");
    sleep(1);
    printf("sleep call #4\n");
    sleep(1);

    printf("Exiting\n");

    

    exit(0);
}

