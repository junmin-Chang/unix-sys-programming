// 환경변수를 변경하거나 set하면, 자기 자신 또는 자식 프로세스에서만 변경됨.
// 부모에게는 적용안됨.
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *val;
    val = getenv("SHELL");
    if (val == NULL) 
        printf("SHELL not defined");
    else
        printf("1. SHELL = %s\n", val);
    
    putenv("SHELL=/usr/bin/csh");
    val = getenv("SHELL");
    printf("2. SHELL = %s\n", val);

    return 0;
}