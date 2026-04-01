#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int n, res=0;
	for (int i=0; i<5;i++){
		scanf("%d", &n);
		res+=n;
	}
	printf("%d\n", res);
	return 0;
}
