#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;   
    int num2 = *(int *)b;   

    if (num1 < num2) 
        return -1;   
    
    if (num1 > num2) 
        return 1;    
    
    return 0;
}

int lower_bound(int arr[], int target, int size) {
	int mid, start, end;
	start = 0, end = size-1;

	while (end > start)
	{
		mid = (start + end) / 2; 
		if (arr[mid] >= target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int ary[1000001], sort_ary[1000001], input[1000001], n;

int main(void) {
	scanf("%d", &n);
	int data, cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		/*if (!cnt) ary[cnt++] = input[i];
		else {
			int c = 0;
			for (int j = 0; j < cnt; j++) {
				if (ary[j] == input[i]) c = 1;
			}
			if (c == 0) ary[cnt++] = input[i];
		}*/
	}
	memcpy(sort_ary, input, sizeof(input));
	qsort(sort_ary, n, sizeof(int), compare);
	
	int pre_data;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			pre_data = sort_ary[i];
			ary[cnt++] = pre_data;
		}
		else {
			if (pre_data != sort_ary[i]) {
				pre_data = sort_ary[i];
				ary[cnt++] = pre_data;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", lower_bound(ary, input[i], cnt));
	}puts("");
	
	return 0;
}
