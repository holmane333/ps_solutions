#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
int stick[7] = { 64,32,16,8,4,2,1 };

int main() {
	char chess[9][9];
	for (int i = 0; i < 8; i++) scanf("%s", chess[i]);
	int result = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				if (chess[i][j] == 'F') result++;
			}
		}
	}
	printf("%d", result);
	
	
	return 0;
}