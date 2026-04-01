#include <stdio.h>
#pragma warning(disable:4996)

int n;

char base[4][7] = {
	"  *  ", 
	" * * ", 
	"*****"
};
char res[5000][8000];

void loop(int x, int y, int c) {
	//printf("%d %d %d\n", x, y, c);
	if (c == 1) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 5; ++j) {
				res[i + y][j + x] = base[i][j];
			}
		}
		return;
	}
	loop(x + 3 * c / 2, y, c / 2);
	loop(x, y + 3 * c / 2, c / 2);
	loop(x + 3 * c, y + 3 * c / 2, c / 2);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) for (int j = 0; j < 2 * n - 1; ++j) res[i][j] = ' ';
	for (int i = 0; i < n; ++i) res[i][2 * n - 1] = '\0';
	loop(0, 0, n / 3);
	for (int i = 0; i < n; ++i) {
		printf("%s\n", res[i]);
	}
	
	return 0;
}
