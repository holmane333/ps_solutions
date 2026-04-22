#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dist[3010][3010];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < k; i++) {
        int y, x, p;
        cin >> y >> x >> p;
        if (dist[y][x] < p) {
            dist[y][x] = p;
        }
    }

    queue<pair<int, int>> q[3005]; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dist[i][j] > 0) {
                q[dist[i][j]].push({i, j}); 
            }
        }
    }

    for (int p = 3000; p > 0; p--) {
        while (!q[p].empty()) {
            pair<int, int> curr = q[p].front();
            q[p].pop();

            int cy = curr.first;
            int cx = curr.second;
            int cp = dist[cy][cx];

            if (cp > p) continue; 

            for (int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (ny < 1 || ny > n || nx < 1 || nx > m) continue;

                if (dist[ny][nx] < cp - 1) {
                    dist[ny][nx] = cp - 1;
                    q[cp - 1].push({ny, nx}); 
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dist[i][j] >= 0) res++;
        }
    }

    cout << res << "\n";

    return 0;
}