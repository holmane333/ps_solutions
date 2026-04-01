#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a;
int p[110] = {0,}, t, v[110][4] = {0,}, res[110] = {0,}, top[20000010]; //0: size, 1: pos, 3: num
int siz, pos, num, c;
pair<int, int> s[110];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		s[i - 1].first = a;
		s[i - 1].second = i;
		p[i] = a;
		for (int j = 1; j < i; ++j) {
			p[i] = max(p[i], p[j] + min(s[j - 1].first, a) * 2);
		}
	}
	sort(s, s + n);
	memset(top, -1, sizeof(top));
	for (int i = n - 1; i >= 0; --i) {
		//cout << s[i].first << ' ' << s[i].second << '\n';
		for (int j = p[s[i].second] - s[i].first; j < p[s[i].second] + s[i].first; ++j) {
			if (top[j] == -1) top[j] = s[i].second;
		}
	}
	for (int i = 0; i <= 20000001; ++i) {
		if (top[i] != -1) res[top[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (res[i]) cout << i << ' ';
	}
	cout << '\n';
	return 0;
}