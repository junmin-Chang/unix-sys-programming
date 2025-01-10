#include <stdio.h>

int main(void) {
    char str1[20];
    char str2[20];
    scanf("%[ab12]%s", str1, str2);

    printf("%s %s\n", str1, str2);
}