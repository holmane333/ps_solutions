#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n;

void preorder(char tree[][2], char idx) {
	if (idx !=0) {
		printf("%c", idx);
		preorder(tree, tree[(int)(idx - 'A')][0]);
		preorder(tree, tree[(int)(idx - 'A')][1]);
	}
}

void inorder(char tree[][2], char idx) {
	if (idx != 0) {
		inorder(tree, tree[(int)(idx - 'A')][0]);
		printf("%c", idx);
		inorder(tree, tree[(int)(idx - 'A')][1]);
	}
}

void postorder(char tree[][2], char idx) {
	if (idx!=0) {
		postorder(tree, tree[(int)(idx - 'A')][0]);
		postorder(tree, tree[(int)(idx - 'A')][1]);
		printf("%c", idx);
	}
}

int main() {
	char tree[100][2], a, b, c;
	scanf("%d", &n);
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %c", &a, &b, &c);
		if (b != '.') tree[(int)(a - 'A')][0] = b;
		if (c != '.') tree[(int)(a - 'A')][1] = c;
	}

	preorder(tree, 'A');
	puts("");
	inorder(tree, 'A');
	puts("");
	postorder(tree, 'A');
	puts("");

	return 0;
}
