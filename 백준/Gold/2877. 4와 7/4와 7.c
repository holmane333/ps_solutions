#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	long long int n, n_copy, len=1LL;
	scanf("%lld", &n);
	n_copy=n-1;
	long long int t=2LL;
	while (1){
		if (n_copy<t) break;
		n_copy-=t;
		t<<=1;
		len++;
	}
	for (int i=len-1;i>=0;i--){
		printf("%d",(n_copy>>i)%2?7:4);
	}
	puts("");
}
