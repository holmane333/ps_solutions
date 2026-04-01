#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct data {
	int inp_char[2];
	double per[3];
}data;

data input[100];
double ans[100];

void dfs(int idx, int res[4], double percent) {
	if (idx == 6) {
		int sorted_data[4][2];
		for (int i = 0; i < 4; i++) {
			sorted_data[i][0] = i;
			sorted_data[i][1] = res[i];
		}
		for (int i = 0; i < 4; i++) {
			int now = i, temp;
			for (int j = i + 1; j < 4; j++) {
				if (sorted_data[now][1] < sorted_data[j][1]) now = j;
			}
			for (int j = 0; j < 2; j++)
				swap(sorted_data[now][j], sorted_data[i][j], temp);
		}
		if (sorted_data[0][1] == sorted_data[1][1] && sorted_data[0][1] == sorted_data[2][1] && sorted_data[0][1] == sorted_data[3][1]) {
			for (int i = 0; i < 4; i++) ans[sorted_data[i][0]] += percent * (1.0 / 2.0);
		}
		else if (sorted_data[0][1] > sorted_data[1][1] && sorted_data[1][1] == sorted_data[2][1] && sorted_data[1][1] == sorted_data[3][1]) {
			ans[sorted_data[0][0]] += percent;
			for (int i = 1; i < 4; i++) ans[sorted_data[i][0]] += percent * (1.0 / 3.0);
		}
		else if (sorted_data[0][1] == sorted_data[1][1] && sorted_data[0][1] == sorted_data[2][1]) {
			for (int i = 0; i < 3; i++) {
				ans[sorted_data[i][0]] += percent * (2.0 / 3.0);
			}
		}
		else if (sorted_data[0][1] > sorted_data[1][1] && sorted_data[1][1] == sorted_data[2][1]) {
			ans[sorted_data[0][0]] += percent;
			for (int i = 1; i < 3; i++) ans[sorted_data[i][0]] += percent * (1.0 / 2.0);
		}
		else {
			for (int i = 0; i < 2; i++) ans[sorted_data[i][0]] += percent;
		}
	}
	else {
		res[input[idx].inp_char[0]] += 3;
		dfs(idx + 1, res, percent * input[idx].per[0]);
		res[input[idx].inp_char[0]] -= 3;

		res[input[idx].inp_char[0]] += 1;
		res[input[idx].inp_char[1]] += 1;
		dfs(idx + 1, res, percent * input[idx].per[1]);
		res[input[idx].inp_char[0]] -= 1;
		res[input[idx].inp_char[1]] -= 1;

		res[input[idx].inp_char[1]] += 3;
		dfs(idx + 1, res, percent * input[idx].per[2]);
		res[input[idx].inp_char[1]] -= 3;
	}
}

int main() {
	char str[4][15], inp1[11], inp2[11];
	for (int i = 0; i < 4; i++) {
		scanf("%s", str[i]);
	}
	double win, draw, lose;
	for (int i = 0; i < 6; i++) {
		scanf("%s %s %lf %lf %lf", inp1, inp2, &win, &draw, &lose);
		for (int j = 0; j < 4; j++) {
			if (!strcmp(inp1, str[j])) input[i].inp_char[0] = j;
			if (!strcmp(inp2, str[j])) input[i].inp_char[1] = j;
		}
		input[i].per[0] = win;
		input[i].per[1] = draw;
		input[i].per[2] = lose;
	}
	int res[4] = { 0, };
	dfs(0, res, 1.0);

	for (int i = 0; i < 4; i++) {
		printf("%.10lf\n", ans[i]);
	}
	return 0;
}