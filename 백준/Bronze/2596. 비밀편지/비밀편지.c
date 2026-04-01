#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

char mat[10][10] = {
	{'0','0','0','0','0','0'}, // A
	{'0','0','1','1','1','1'}, // B
	{'0','1','0','0','1','1'}, // C
	{'0','1','1','1','0','0'}, // D
	{'1','0','0','1','1','0'}, // E
	{'1','0','1','0','0','1'}, // F
	{'1','1','0','1','0','1'}, // G
	{'1','1','1','0','1','0'}  // H
};

char mat_data[10] = { 'A','B','C','D','E','F','G','H' };
char res[15];

int main() {
	int n, c = -1;
	scanf("%d", &n);
	char data[1000];
	scanf("%s", data);
	for (int i = 0; i < n * 6; i += 6) {
		int check = -1;
		for (int j = 0; j < 8; j++) {
			int cnt = 0;
			for (int k = 0; k < 6; k++) {
				if (data[i + k] != mat[j][k]) cnt++;
			}
			if (cnt <= 1) {
				check = j;
				break;
			}
		}
		if (check != -1) {
			res[i / 6] = mat_data[check];
		}
		else {
			c = i / 6 + 1;
			break;
		}
	}
	if (c != -1) printf("%d\n", c);
	else {
		for (int i = 0; i < n; i++) {
			printf("%c", res[i]);
		}
	}

	return 0;
}