#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, cnt = 0;
	string s, temp = "skeep";
	cin >> n >> s;
	
	int top = 0, stack[1000001] = {0, }, l = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == temp[l]) {
			stack[top++] = l++;
		}
		else if (s[i] == temp[0]) {
			stack[top++] = 0;
			l = 1;
		}
		else {
			top = l = 0;
		}
		while (l == 5) {
			top -= 5;
			l = 0;
			++cnt;
			if (top > 0) {
				l = stack[top - 1] + 1;
				stack[top++] = l++;
			}
		}
	}

	cout << cnt;
	return 0;
}