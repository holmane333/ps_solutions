#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(){
	int tc, t, m, cnt;
	scanf("%d", &tc);
	while(tc--) {
		cnt = 0;
		m = 1e9;
		for(int i = 0; i < 7; ++i) {
			scanf("%d", &t);
			if (!(t & 1)) {
				cnt += t;
				m = min(m, t);
			}
		}
		printf("%d %d\n", cnt, m);
	}
	return 0;
}
