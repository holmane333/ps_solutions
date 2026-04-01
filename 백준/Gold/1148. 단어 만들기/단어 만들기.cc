#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[200010][30] = {0,}, b[30], v[30];
char s[20];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (1) {
		cin >> s;
		if (s[0] == '-') break;
		for (int i = 0; i < strlen(s); ++i) {
			++a[n][(int)(s[i] - 'A')];
		}
		++n;
	}
	while (1) {
		cin >> s;
		if (s[0] == '#') break;
		memset(b, 0, sizeof(b));
		memset(v, 0, sizeof(v));
		for (int i = 0; i < strlen(s); ++i) {
			b[(int)(s[i] - 'A')]++;
		}
		int c;
		for (int i = 0; i < n; ++i) {
			c = 0;
			for (int j = 0; j < 26; ++j) {
				if (b[j] < a[i][j]) {
					c = 1;
					break;
				}
			}
			if (c) continue;
			for (int j = 0; j < 26; ++j) {
				v[j] += (a[i][j] > 0);
			}
		}
		int minv = 1e9, maxv = -1e9;
		for (int i = 0; i < 26; ++i) {
			if (b[i] != 0) {
				minv = min(minv, v[i]);
				maxv = max(maxv, v[i]);
			}
		}

		for (int i = 0; i < 26; ++i) {
			if (b[i] != 0 && v[i] == minv) cout << (char)(i + 'A');
		}
		cout << ' ' << minv << ' ';
		for (int i = 0; i < 26; ++i) {
			if (b[i] != 0 && v[i] == maxv) cout << (char)(i + 'A');
		}
		cout << ' ' << maxv << '\n';
	}

	return 0;
}