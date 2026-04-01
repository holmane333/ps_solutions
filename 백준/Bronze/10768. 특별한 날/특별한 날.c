#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
    int a, b;
    
   scanf("%d %d", &a, &b);
    if (a > 2) printf("After");
    else if (a == 1) printf("Before");
    else if (b > 18) printf("After");
    else if (b == 18) printf("Special");
    else printf("Before");
    return 0;
}