#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c, n, l[110];
vector<int> res, mat[11];

void sosu() {
    for (int i = 2; i <= 100; ++i) l[i] = 1;
    for (int i = 2; i <= 100; ++i) {
        if (l[i] == 1) {
            res.push_back(i);
            for (int j = 2 * i; j <= 100; j += i) {
                l[j] = 0;
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] >= 10 && res[i] < 100) {
            mat[res[i] / 10].push_back(res[i] % 10);
        }
    }
}


void dfs(int i, int t, string s) {
    for (int j = 0; j < mat[i].size(); ++j) {

    }
}
void bfs() {
    int start = a % 10;
    int end = b / 10;
    stack<pair<pair<int, int>, string>> q;
    q.push({ {start, n - 3}, to_string(a)});
    while (q.size()) {
        pair<pair<int, int>, string> tmp = q.top();
        q.pop();
        cout << tmp.first.first << " " << tmp.first.second << "\n";
        for (int i = 0; i < mat[tmp.first.first].size(); ++i) {
            if (tmp.first.second == 1) {
                if (mat[tmp.first.first][i] == end) {
                    cout << tmp.second << b;
                    c = 1;
                    return;
                }
            }
            else q.push({ {mat[tmp.first.first][i], tmp.first.second - 1}, tmp.second + to_string(mat[tmp.first.first][i]) });
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> a >> b >> n;
    sosu();
    if (!l[a] || !l[b] || (b / 10 != 1 && b / 10 != 3 && b / 10 != 7 && b / 10 != 9)) {
        cout << -1;
        return 0;
    }
    string res = to_string(a);
    if (a % 10 == 2 || a % 10 == 5 || a % 10 == 8) {
        res += to_string(3);
        --n;
    }
    else if (a % 10 == 9) {
        res += to_string(7);
        --n;
    }

    for (int i = 0; i < n - 4; ++i) {
        res += to_string(1);
    }
    res += to_string(b);
    cout << res;
    return 0;
}
