#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main() {
	int n, m, time;
	int* recipe[100002], *itemary[100002], *item2res[100002];
	int child[100002];
	scanf("%d %d %d", &n, &m, &time);
	++time;
	for (int i = 0; i <= n; i++) recipe[i] = NULL, itemary[i] = NULL, item2res[i] = (int*)malloc(sizeof(int));
	for (int i = 0; i <= n; ++i) item2res[i][0] = 0;
	int num, t, k, medicine, res[100002] = { 0, }, item[100002] = { 0, }, data;
	int queue[100002][2], ft = 0, rr = 0;
	int c;
	int curr, cutime;
	for (int i = 0; i < m; i++) {
		scanf("%d", &data);
		res[data] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		itemary[i] = (int*)malloc(sizeof(int) * (t + 1)); // itemary: i번 건물로부터 만들 수 있는 물건
		itemary[i][0] = t;
		for (int j = 1; j <= t; j++) {
			scanf("%d", &itemary[i][j]);
			if (res[i] && !item[itemary[i][j]]) {
				item[itemary[i][j]] = 1;
				queue[rr][0] = 1;
				queue[rr++][1] = itemary[i][j];
			}
		}
	}
	//printf("%d\n", rr);
	//for (int i = 0; i < rr; ++i) printf("%d ", queue[i]); puts("");
	for (int i = 1; i <= n - m; i++) {
		scanf("%d", &num);
		scanf("%d", &t);
		child[num] = t;
		recipe[i] = (int*)malloc(sizeof(int) * (t + 2)); // recipe: num 건물을 짓는 데 필요한 물건
		for (int j = 1; j <= t; j++) {
			scanf("%d", &recipe[i][j]);
			item2res[recipe[i][j]] = (int*)realloc(item2res[recipe[i][j]], sizeof(int) * (++item2res[recipe[i][j]][0] + 1)); // item2res: i번 물건을 필요로하는 건물 번호
			item2res[recipe[i][j]][item2res[recipe[i][j]][0]] = num;
		}
		recipe[i][0] = t;
		recipe[i][t + 1] = num;
	}
	/*
	for (int i = 1; i <= n; ++i) {
		printf("%d: ", i);
		for (int j = 1; j <= item2res[i][0]; ++j) {
			printf("%d ", item2res[i][j]);
		}puts("");
	}puts("");
	for (int i = 1; i <= n - m; ++i) {
		printf("%d: ", recipe[i][recipe[i][0] + 1]);
		for (int j = 1; j <= recipe[i][0]; ++j) {
			printf("%d ", recipe[i][j]);
		}puts("");
	}puts("");
	*/
	while (ft != rr) {
		c = 0;
		cutime = queue[ft][0];
		curr = queue[ft++][1]; // 물건 번호
		if (ft > 100000) ft = 0;
		if (cutime + 1 > time) continue;
		for (int i = 1; i <= item2res[curr][0]; ++i) { //얻은 물건으로부터 만들 가능성이 있는 건물 확인
			k = item2res[curr][i];
			--child[k];
			
			if (!child[k]) {
				res[k] = 1;
				for (int j = 1; j <= itemary[k][0]; ++j) {
					if (!item[itemary[k][j]]) {
						item[itemary[k][j]] = 1;
						queue[rr][0] = cutime + 1;
						queue[rr++][1] = itemary[k][j];
					}
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i <= n; i++) if (res[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 0; i <= n; i++) {
		if (res[i]) printf("%d ", i);
	}
	puts("");
	
	return 0;
}