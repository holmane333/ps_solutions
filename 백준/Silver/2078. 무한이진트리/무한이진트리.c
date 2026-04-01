#include<stdio.h>

int l,r;

void loop(int a,int b) {
	if(a == 1 && b == 1) return;
	else if(a == 1) r+=b-1;
	else if(b == 1) l+=a-1;
	else if(a> b){
		l += a / b;
		loop(a % b, b);
	}
	else {
		r += b / a;
		loop(a, b % a);
	}
	return;
}

int main() {
	int a, b;
    scanf("%d %d",&a, &b);
    loop(a, b);
    printf("%d %d\n", l, r);
    
    return 0;
}