#include <stdio.h>
#include <string.h>

int main() {
	char n[1000001];
    int cnt = 0;
    scanf("%s", n);
    if (strlen(n) == 1 && n[0] == '0') {
        printf("0\nNO\n");
        return 0;
    }
    while (strlen(n) != 1) {
        int k = 0;
        for (int i = 0; i < strlen(n); ++i) {
            k += (int)n[i] - '0';
        }
        sprintf(n, "%d", k);
        ++cnt;
    }
    printf("%d\n", cnt);
    if (atoi(n) % 3) printf("NO\n");
    else printf("YES\n");
    return 0;
}