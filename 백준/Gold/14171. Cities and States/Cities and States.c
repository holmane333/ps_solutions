#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int ary[27][27][27][27];

int main() {
	
	int n, ans = 0;
	char input1[11], input2[3];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", input1, input2);
		if (input1[0] == input2[0] && input1[1] == input2[1])
			continue;
		ary[input2[0] - 65][input2[1] - 65][input1[0] - 65][input1[1] - 65]++;
		ans += ary[input1[0] - 65][input1[1] - 65][input2[0] - 65][input2[1] - 65];
	}
	printf("%d\n", ans);


	return 0;
}
