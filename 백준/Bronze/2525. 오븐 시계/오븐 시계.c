#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    b += c;
    a += b / 60;
    b %= 60;
    a %= 24;
    printf("%d %d\n", a, b);
    
    return 0;
}