#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#include <assert.h>

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
typedef struct {
    int l, r;
} Interval;

int compare(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    if (i1->r != i2->r) return i1->r - i2->r;
    return i1->l - i2->l;
}



int main(void) {
	int n, m, n2 = 1;
    scanf("%d %d", &n, &m);
    // assert(n != 6 || m != 2);
	char s1[3000010], s2[6000010];
	long long ary2[6000010] = { 0, };
    Interval intervals[6000010];
	scanf("%s", s1 + 1);
	n = strlen(s1 + 1);
	for (int i = 1; i <= n; ++i) {
		s2[n2++] = '#';
		s2[n2++] = s1[i];
	}
	s2[n2] = '#';
	s2[n2 + 1] = '\0';
	manachers(s2, ary2, n2);
	
	int idx = 0;
	for (int i = 1; i <= n2; i++) {
    int core_len = (i % 2 == m % 2) ? m + 1 : m;
        if (ary2[i] >= core_len) {
            intervals[idx].l = (i - core_len) / 2 + 1;
            intervals[idx].r = (i + core_len) / 2;
            idx++;
        }
    }
    qsort(intervals, idx, sizeof(Interval), compare);

    int last_broken = -1, ans = 0;
    for (int i = 0; i < idx; i++) {
        if (intervals[i].l > last_broken) {
            ans++;
            last_broken = intervals[i].r;
        }
    }
	//for (int i = 1; i <= n2; ++i) printf("%lld ", ary2[i]); puts("");
	printf("%d\n", ans);
	
	return 0;
}