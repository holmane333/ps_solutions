#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main(int argc, char* argv[]) {
	int ary[100002], n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	ary[n++] = 1000000001;
	qsort(ary, n, sizeof(int), cmpfunc);

	for (int i = 0; i < q; i++) {
		int a, b, count = 0;
		scanf("%d %d", &a, &b);

		int result1 = 0, result2 = 0;
		int start = 0;
		int end = n;

		int mid = n;
		while (end - start > 0) { //lower bound
			mid = (start + end) / 2;

			if (ary[mid] < a) {
				start = mid + 1;
			}
			else {
				end = mid;
			}
		}
		result1 = end + 1;
		//if (ary[result1] > a) result1++;
		//if (ary[result1] != a) count++;
		start = 0; end = n;

		while (end - start > 0) { //upper bound
			mid = (start + end) / 2;

			if (ary[mid] <= b) {
				start = mid + 1;
			}
			else {
				end = mid;
			}

		}

		result2 = end + 1;
		printf("%d\n", result2 - result1);
	}


	return 0;
}
