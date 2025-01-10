#include <stdio.h>

int main(void) {
    int i1, i2;
    float flt;
    char str1[10], str2[10];

    scanf("%2d %2d %f %s %s", &i1, &i2, &flt, str1, str2);

    printf("%2d %2d %.2f %s %s", i1, i2, flt, str1, str2);
    scanf("%s", str1);
    printf("%s", str1);
    return 0;

}