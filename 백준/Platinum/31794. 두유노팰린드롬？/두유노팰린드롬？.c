#include <stdio.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

char s1[1000010], s2[2000010];
long long ary2[2000010] = { 0, };
long long L[2000010] = { 0, }, R[2000010] = { 0, };
long long res[2000010] = { 0, };

void manachers(char s[], long long ary[], int n) {
    long long r = 0LL, p = 0LL;
    for (int i = 1; i <= n; i++) {
        if (i <= r)
            ary[i] = min(ary[2 * p - i], r - i);
        else
            ary[i] = 0LL;

        while (i - ary[i] - 1 > 0 && i + ary[i] + 1 <= n && s[i - ary[i] - 1] == s[i + ary[i] + 1])
            ary[i] += 1LL;
        
        if (r < i + ary[i]) {
            r = i + ary[i];
            p = i;
        }
    }
}

int main(void) {
    int n, m, n2 = 1;
    
    scanf("%s", s1 + 1);
    n = strlen(s1 + 1);
    // assert(strcmp(s1 + 1, "abcdefef"));
    for (int i = 1; i <= n; ++i) {
        s2[n2++] = '#';
        s2[n2++] = s1[i];
    }
    s2[n2] = '#';
    s2[n2 + 1] = '\0';
    manachers(s2, ary2, n2);
    for (int i = 1; i <= n2; ++i) {
        int r = ary2[i];
        if (r == 0) continue;
        
        int S = (i - r + 1) / 2;
        int E = (i + r - 1) / 2;
        int mid_L = (i) / 2;
        int mid_R = (i + 1) / 2;
        ++L[S];
        --L[mid_L + 1];

        // 끝점 기록 (무조건 mid_R - 1 을 빼야 상쇄되지 않음)
        ++R[E];
        --R[mid_R - 1];
    }
    for (int i = 1; i <= n; ++i) L[i] += L[i-1];
    for (int i = n; i >= 1; --i) R[i] += R[i+1];
    //for (int i = 1; i <= n2; ++i) printf("%lld ", ary2[i]); puts("");
    

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        res[i] = res[i - 1] + L[i] - R[i - 1];
    }

    int q, a;
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &a);
        printf("%lld\n", res[a] - 1);
    }
    
    return 0;
}