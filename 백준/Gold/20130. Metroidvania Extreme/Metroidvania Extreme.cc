#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char w[210][210];
int res[40010][3], idx;
int n, m, init[2], fin[2], v[210][210], item, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		w[i][0] = '#';
		cin >> (w[i] + 1);
		for (int j = 1; j <= m; ++j) {
			if (w[i][j] == '@') {
				init[0] = i;
				init[1] = j;
			}
			if (w[i][j] == '!') {
				fin[0] = i;
				fin[1] = j;
			}
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	v[init[0]][init[1]] = 1;
	q.push(make_pair(make_pair(init[0], init[1]), make_pair(0, 0)));
	while (q.size()) {
		pair<pair<int, int>, pair<int, int>> p = q.front(); q.pop();
		//cout << p.first.first << ' ' << p.first.second << ' ' << p.second << ' ' << item <<  '\n';
		p.second.first = (p.second.first & item) ^ p.second.first;
		if (p.second.first) {
			q.push(p);
			continue;
		}
		item |= p.second.second;
		res[idx][0] = p.first.first;
		res[idx++][1] = p.first.second;
		
		for (int i = 0; i < 4; ++i) {
			int cx = p.first.first + dx[i];
			int cy = p.first.second + dy[i];
			if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
			if (v[cx][cy]) continue;
			if (w[cx][cy] == '#') continue;
			if (w[cx][cy] == '!') {
				res[idx][0] = cx;
				res[idx++][1] = cy;
				cout << idx << '\n';
				for (int j = 0; j < idx; ++j) {
					cout << res[j][0] << ' ' << res[j][1] << '\n';
				}
				return 0;
			}
			int temp = 0, temp2 = 0;
			if (w[cx][cy] >= 'A' && w[cx][cy] <= 'Z')
				temp = (1 << ((int)w[cx][cy] - (int)'A'));
			if (w[cx][cy] >= 'a' && w[cx][cy] <= 'z')
				temp2 |= (1 << ((int)w[cx][cy] - (int)'a'));
			v[cx][cy] = 1;
			q.push(make_pair(make_pair(cx, cy), make_pair(temp, temp2)));
		}
	}



	return 0;
}