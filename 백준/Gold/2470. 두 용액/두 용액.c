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

int compare(const void* a, const void* b) {
	int pa = *(long long int*)a;
	int pb = *(long long int*)b;
	if (pa > pb) return 1;
	else if (pa < pb) return -1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &data[i]);
	}
	qsort(data, n, sizeof(long long int), compare);
	int low = 0, high = n - 1;
	int left = INT_MIN, right = INT_MAX;
	long long int res = LLONG_MAX;
	while (low < high) {
		long long int sum = data[low] + data[high];
		long long int ab = abs(sum);
		if (ab < res) {
			res = ab;
			left = low;
			right = high;
		}
		if (sum < 0) low++;
		else high--;
	}
	
	printf("%lld %lld\n", data[left], data[right]);
	return 0;
}