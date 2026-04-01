#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int board[7][7], v[7][7], n = 5, depth = 0, res = 0, nowapple = 0;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	if (depth > 3) return;
	if (nowapple >= 2) res = 1;
	for (int i = 0; i < 4; ++i) {
		if (res) return;
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx <= 0 || cx > 5 || cy <= 0 || cy > 5 || board[cx][cy] == -1 || v[cx][cy]) continue;
		v[cx][cy] = 1;
		if (board[cx][cy] == 1) nowapple++;
		depth++;
		dfs(cx, cy);
		depth--;
		if (board[cx][cy] == 1) nowapple--;
		v[cx][cy] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int r, c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}
	
	cin >> r >> c;
	++r; ++c;
	v[r][c] = 1;
	dfs(r, c);

	cout << res;

	return 0;
}