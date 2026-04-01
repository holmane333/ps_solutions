#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
    int a, b, c, res;
    scanf("%d %d %d", &a, &b, &c);
    
    if (a == b && b == c) res = 10000 + 1000 * a;
    else if (a == b || a == c) res = 1000 + 100 * a;
    else if (b == c) res = 1000 + 100 * c;
    else res = max(max(a, b), c) * 100;
    
    printf("%d\n", res);
    return 0;
}