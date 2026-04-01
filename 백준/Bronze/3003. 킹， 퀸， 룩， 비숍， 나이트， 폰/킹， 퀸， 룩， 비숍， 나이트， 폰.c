#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(){
	int n;
	int ary[]={1,1,2,2,2,8};
	for (int i=0;i<6;i++){
		scanf("%d", &n);
		printf("%d ", ary[i]-n);
	}
	
	
	return 0;
}
