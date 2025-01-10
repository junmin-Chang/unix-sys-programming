#include <stdio.h>

// dict_elem 자료 사전 원소
// 데이터베이스 레코드의 한 필드를 기술한다.

struct dict_elem {
    char d_name[15];
    int d_start;
    int d_length;
    int d_type;
};

#define ERROR   -1
#define SUCCESS  0

