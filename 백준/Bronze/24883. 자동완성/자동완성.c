#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
    char a;
    scanf("%c", &a);
    if (a == 'N' || a == 'n') printf("Naver D2\n");
    else printf("Naver Whale\n");
    
    return 0;
}