#pragma warning(disable:4996)
#include <stdio.h>

char s[60], res = 1;

void r(int t) {
	if (t == 0) {
		res = 0;
		return;
	} 
	if (s[t] == '1' || s[t] == '4') {
		r(t - 1);
		if (s[t] == '1') s[t] = '2';
		else s[t] = '3';
	}
	else {
		if (s[t] == '2') s[t] = '1';
		else s[t] = '4';
	}
}

void l(int t) {
	if (t == 0) {
		res = 0;
		return;
	} 
	if (s[t] == '2' || s[t] == '3') {
		l(t - 1);
		if (s[t] == '2') s[t] = '1';
		else s[t] = '4';
	}
	else {
		if (s[t] == '1') s[t] = '2';
		else s[t] = '3';
	}
}

void u(int t) {
	if (t == 0) {
		res = 0;
		return;
	} 
	if (s[t] == '1' || s[t] == '2') {
		u(t - 1);
		if (s[t] == '1') s[t] = '4';
		else s[t] = '3';
	}
	else {
		if (s[t] == '3') s[t] = '2';
		else s[t] = '1';
	}
}

void d(int t) {
	if (t == 0) {
		res = 0;
		return;
	}
	if (s[t] == '3' || s[t] == '4') {
		d(t - 1);
		if (s[t] == '3') s[t] = '2';
		else s[t] = '1';
	}
	else {
		if (s[t] == '2') s[t] = '3';
		else s[t] = '4';
	}
}


int main(void) {
	int t, pt;
	long long x, y;
	scanf("%d %s", &t, s + 1);
	scanf("%lld %lld", &x, &y);
	pt = t;
	if (x > 0LL) {
		while (x) {
			if (x % 2LL) r(pt);
			x /= 2LL;
			--pt;
			//printf("%s\n", s + 1);
		}
	}
	else {
		x *= -1LL;
		while (x) {
			if (x % 2LL) l(pt);
			x /= 2LL;
			--pt;
			//printf("%s\n", s + 1);
		}
	}
	
	pt = t;
	if (y > 0LL) {
		while (y) {
			if (y % 2LL) u(pt);
			y /= 2LL;
			--pt;
			//printf("%s\n", s + 1);
		}
	}
	else {
		y *= -1LL;
		while (y) {
			if (y % 2LL) d(pt);
			y /= 2LL;
			--pt;
			//printf("%s\n", s + 1);
		}
	}
	
	if (res) printf("%s\n", s + 1);
	else printf("-1\n");
	return 0;
}
