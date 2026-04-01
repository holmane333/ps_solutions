#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

long long int data[100001];

int static compare(const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &data[i]);
	}
	qsort(data, n, sizeof(long long int), compare);
	int low, high;
	int left = INT_MIN, right = INT_MAX, mid = 0;
	long long int res = LLONG_MAX;
	for (int i = 0; i < n - 1; i++) {
		low = i + 1;
		high = n - 1;
		while (low < high) {
			long long int sum = data[low] + data[i] + data[high];
			long long int ab = sum > 0 ? sum : sum * -1LL;
			if (ab < res) {
				res = ab;
				left = i;
				mid = low;
				right = high;
			}
			if (sum < 0) low++;
			else high--;
		}
	}
	
	printf("%lld %lld %lld\n", data[left], data[mid], data[right]);
	return 0;
}