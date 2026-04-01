#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))


int main() {
	int n;
	int queue[2000002], top = 0, bot = 0;
	char str[20], str1[5];
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(str);
		if (str[1] == 'u') { //push
			sscanf(str, "%s %d", str1, &queue[top++]);
			top %= 2000001;
		}
		else if (str[0] == 'p') { //pop
			if (top == bot) puts("-1");
			else {
				printf("%d\n", queue[bot++]);
				bot %= 2000001;
			}
		}
		else if (str[0] == 's') { //size
			printf("%d\n", abs(top - bot));
		}
		else if (str[0] == 'e') { //empty
			printf("%d\n", top - bot == 0 ? 1 : 0);
		}
		else if (str[0] == 'f') { //front
			if (top == bot) puts("-1");
			else printf("%d\n", queue[bot]);
			
		}
		else { //back
			if (top == bot) puts("-1");
			else printf("%d\n", queue[top > 0 ? top - 1 : 2000000]);
			
		}
	}



	return 0;
}

