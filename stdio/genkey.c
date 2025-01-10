#include <stdio.h>
#include <string.h>

// database에서 사용할 key 생성
// key는 20자리 문자
char *genkey(char *buf, const char *suppcode, long orderno) {
    if (strlen(suppcode) != 10) 
        return NULL;
    sprintf(buf, "%s_%.9ld", suppcode, orderno);

    return buf; 
}

int main(void) {
    char key[20];
    printf("key is %s\n", genkey(key, "abcdefghij", 12));
}