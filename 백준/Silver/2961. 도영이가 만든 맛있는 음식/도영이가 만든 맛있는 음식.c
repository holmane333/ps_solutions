#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#pragma warning(disable:4996)

int n, min=INT_MAX, ary[11][2];

void dfs(int t, int a, int b, int cnt){
	if (t==n) {
		if (abs(a-b)<min && cnt!=0) min=abs(a-b);
		return;
	}
	dfs(t+1, a, b, cnt);
	dfs(t+1, a*ary[t][0], b+ary[t][1], cnt+1);
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		scanf("%d %d",&ary[i][0], &ary[i][1]);
	}
	dfs(0, 1, 0, 0);
	printf("%d\n",min);
}
