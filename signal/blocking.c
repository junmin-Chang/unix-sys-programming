#include <signal.h>
#include <stdio.h>

int main(void) {
    sigset_t set1, set2;

    sigfillset(&set1);

    // SIGINT, SIGQUIT를 포함하지 않는 집합 생성
    sigfillset(&set2);
    sigdelset(&set2, SIGINT);
    sigdelset(&set2, SIGQUIT);

    // 중대하지 않은 코드 수행...

    // 봉쇄
    sigprocmask(SIG_SETMASK, &set1, NULL);

    // 중대한 코드 수행..

    // 하나의 봉쇄 제거
    sigprocmask(SIG_UNBLOCK, &set2, NULL);

    // 덜 중대한 코드 수행

    // 모든 시그널 봉쇄 제거
    sigprocmask(SIG_UNBLOCK, &set1, NULL);


    return 0;
}