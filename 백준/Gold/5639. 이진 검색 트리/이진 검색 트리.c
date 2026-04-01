#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

typedef struct node* NODE;
typedef struct node {
	int key;
	NODE ltchild, rtchild;
}node;

void addtree(NODE tree, int n) {
	if (tree->key == n || tree == NULL) return;
	else {
		if (tree->key > n) {
			if (tree->ltchild == NULL) {
				NODE new1 = (NODE)malloc(sizeof(node));
				new1->key = n;
				new1->ltchild = NULL;
				new1->rtchild = NULL;
				tree->ltchild = new1;
			}
			else addtree(tree->ltchild, n);
		}
		else {
			if (tree->rtchild == NULL) {
				NODE new1 = (NODE)malloc(sizeof(node));
				new1->key = n;
				new1->ltchild = NULL;
				new1->rtchild = NULL;
				tree->rtchild = new1;
			}
			else addtree(tree->rtchild, n);
		}
	}
}

void postorder(NODE tree) {
	if (tree) {
		postorder(tree->ltchild);
		postorder(tree->rtchild);
		printf("%d\n", tree->key);
	}
}

int main() {
	NODE tree = (NODE)malloc(sizeof(node));
	tree->key = NULL;
	tree->ltchild = NULL;
	tree->rtchild = NULL;
	
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == EOF) break;
		if (tree->key == NULL) tree->key = n;
		else addtree(tree, n);
	}

	postorder(tree);

	return 0;
}
