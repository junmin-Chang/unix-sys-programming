#include <signal.h>

sigset_t mask1, mask2;

// 빈 집합 생성
sigemptyset(&mask1);

// 시그널 추가 
sigaddset(&mask1, SIGINT);
sigaddset(&mask1, SIGQUIT);

// 모든 시그널 포함된 집합 
sigfillset(&mask2);

// 시그널 삭제
sigdelset(&mask2, SIGCHLD);


