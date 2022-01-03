#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int visit[20002];

typedef struct node* NODE;
typedef struct node{
	NODE next;
	int d;
}node;

NODE *map;

int check;

void dfs(int d) {
	if (!visit[d]) visit[d] = 1;
	
	NODE curnode = map[d]->next;
	map[d]->next = NULL;
	while(curnode) {
		if (!visit[curnode->d]) {
			if (visit[d] == 1) {
				visit[curnode->d] = 2;
			}
			else {
				visit[curnode->d] = 1;
			}
			dfs(curnode->d);
		}
		else {
			if (visit[curnode->d] == visit[d]) check = 1;
		}
		NODE frenode = curnode;
		curnode = curnode->next;
		free(frenode);
	}
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	map = (NODE*)malloc(20002 * sizeof(NODE));
	for (int i = 0; i < 20002; i++) {
		map[i] = (NODE)malloc(sizeof(node));
	}
	for (int test = 0; test < tc; test++) {
		int v, e;
		memset(visit, 0, sizeof(visit));
		check = 0;
		scanf("%d %d", &v, &e);
		for (int i = 1; i <= v; i++) {
			map[i]->next = NULL;
			map[i]->d = 0;
		}
		for (int i = 0; i < e; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			NODE new1 = (NODE)malloc(sizeof(node));
			NODE new2 = (NODE)malloc(sizeof(node));
			new1->d = y;
			new2->d = x;
			new1->next = map[x]->next;
			map[x]->next = new1;
			new2->next = map[y]->next;
			map[y]->next = new2;
		}
		for (int i = 1; i <= v; i++) {
			if (!visit[i]) dfs(i);
		}
		if (check == 1) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
