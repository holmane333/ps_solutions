#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	int n, k, arr[1001][4], idx = 0, cnt = 1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
		if (arr[i][0] == k) idx = i;
	}
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		if ((arr[i][1] > arr[idx][1]) || (arr[i][1] == arr[idx][1] && arr[i][2] > arr[idx][2]) || (arr[i][1] == arr[idx][1] && arr[i][2] == arr[idx][2] && arr[i][3] > arr[idx][3])) cnt++;
	}
	printf("%d\n", cnt);


	return 0;
}