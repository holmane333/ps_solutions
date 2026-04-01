#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
    int n, cnt = 0;
    char a[20];
    scanf("%d %s", &n, a);
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == 'A') ++cnt;
    }
    
    if (cnt * 2 == n) puts("Tie");
    else if (cnt * 2 < n) puts("B");
    else puts("A");
    return 0;
}