#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node* NODE;
typedef struct node {
	char x;
	NODE L, R;
} node;

int main(void) {
	NODE start = (NODE)malloc(sizeof(node)), right = (NODE)malloc(sizeof(node));
	start->x = '\0';
	start->L = NULL;
	start->R = right;
	right->x = '\n';
	right->L = start;
	right->R = NULL;
	NODE curr = start;
	
	char s[100010];
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {
		NODE new1 = (NODE)malloc(sizeof(node));
		new1->x = s[i];
		new1->L = curr;
		new1->R = curr->R;
		curr->R->L = new1;
		curr->R = new1;
		curr = curr->R;
	}
	
	curr = curr->R;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char c[3];
		scanf("%s", c);
		if (c[0] == 'P') {
			scanf("%s", c);
			NODE new1 = (NODE)malloc(sizeof(node));
			new1->x = c[0];
			new1->L = curr->L;
			new1->R = curr;
			curr->L->R = new1;
			curr->L = new1;
		}
		else if (c[0] == 'L') {
			if (curr->L != start) {
				curr = curr->L;
			}
		}
		else if (c[0] == 'D') {
			if (curr->R != NULL) {
				curr = curr->R;
			}
		}
		else {
			if (curr->L != start) {
				curr->L->L->R = curr;
				curr->L = curr->L->L;
			}
		}
	}
	
	curr = start->R;
	while (curr) {
		printf("%c", curr->x);
		curr = curr->R;
	}
	return 0;
}
