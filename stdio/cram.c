#include <stdio.h>
#include <math.h>

int main(void) {
    char *weekday = "Sunday";
    char *month = "September";
    char *string = "Hello, world";

    int i = 11058;
    int day = 15, hour = 16, minute = 25;

    printf("Date is %s, %d, %s, %d:%.2d\n", weekday, day, month, hour, minute);

    putchar('\n');

    printf(">>%s<<\n", string);
    printf(">>%30s<<\n", string);
    printf(">>%-30s<<\n", string);
    printf(">>%30.5s<<\n", string);
    printf(">>%-30.5s<<\n", string);

    putchar('\n');

    printf("%d, %u, %o, %x, %X\n", i, i, i, i, i);

    printf("PI is %.5f\n", 4*atan(1.0));

    return 0;
}