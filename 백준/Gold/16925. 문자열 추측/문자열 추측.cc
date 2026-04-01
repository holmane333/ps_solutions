#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a;
char res[220];
pair<string, int> s[220];
string str[4];

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.first.length() < b.first.length()) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 2 * n - 2; ++i) {
		cin >> s[i].first;
		s[i].second = i;
	}

	sort(s, s + 2 * n - 2, cmp);
	str[0] = s[0].first + s[2 * n - 2 - 2].first;
	str[1] = s[0].first + s[2 * n - 2 - 1].first;
	str[2] = s[1].first + s[2 * n - 2 - 2].first;
	str[3] = s[1].first + s[2 * n - 2 - 1].first;

	int c = 0;
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < 2 * n - 2; i += 2) {
			c = 0;
			if (str[k].substr(0, i / 2 + 1) == s[i].first && str[k].substr(n - i / 2 - 1, i / 2 + 1) == s[i + 1].first) {
				res[s[i].second] = 'P';
				res[s[i + 1].second] = 'S';
				c = 1;
			}
			else if (str[k].substr(0, i / 2 + 1) == s[i + 1].first && str[k].substr(n - i / 2 - 1, i / 2 + 1) == s[i].first) {
				res[s[i].second] = 'S';
				res[s[i + 1].second] = 'P';
				c = 1;
			}
			if (!c) break;
		}
		if (!c) continue;
		cout << str[k] << '\n';
		for (int i = 0; i < 2 * n - 2; ++i) {
			cout << res[i];
		}
		cout << '\n';
		break;
	}
	return 0;
}