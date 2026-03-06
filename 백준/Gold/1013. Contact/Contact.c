#include <stdio.h>
#include <regex.h>
#include <sys/types.h>

int main(void) {
	regex_t state;
	const char* s = "^(100+1+|01)+$";
	char a[210];
	regcomp(&state, s, REG_EXTENDED);
	int tc, res;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", a);
		res = regexec(&state, a, 0, NULL, 0);
		if (!res) puts("YES");
		else puts("NO");
	}
	
	return 0;
}
