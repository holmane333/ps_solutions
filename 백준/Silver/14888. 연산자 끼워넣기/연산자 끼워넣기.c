#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int min=2000000000, max=-2000000000;
int mat1[15], mat2[15];
int op[15], result[15];

void z(int count,int n) {
	if (count == n) {
		int sum = mat1[0];
		for (int i = 1; i < n; i++) {
			int sign = op[i];
			switch (sign)
			{
			case 1:
				sum += mat1[i];
				break;
			case 2:
				sum -= mat1[i];
				break;
			case 3:
				sum *= mat1[i];
				break;
			case 4:
				sum /= mat1[i];
				break;
			}
		}
		max = max > sum ? max : sum;
		min = min < sum ? min : sum;
		return;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (mat2[i]) continue;
			op[count] = result[i];
			mat2[i] = 1;
			z(count + 1, n);
			op[count] = 0;
			mat2[i] = 0;
		}
	}
}

int main() {
	int n, num, c = 1;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &mat1[i]);
	}
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &num);
		for (int j = 0; j < num; j++) {
			result[c++] = i;
		}
	}
	z(1, n);
	printf("%d\n%d\n", max, min);
	return 0;
}