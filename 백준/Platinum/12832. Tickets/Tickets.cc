#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<pair<int, int>>> l(N + 1);

    for (int i = 1; i <= M; ++i) {
        int s, e;
        cin >> s >> e;
        if (s <= N) {
            l[s].push_back({e, i});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> res;

    for (int i = 1; i <= N; ++i) {
        for (const auto& req : l[i]) {
            pq.push(req);
        }

        while (!pq.empty() && pq.top().first < i) {
            pq.pop();
        }

        if (!pq.empty()) {
            res.push_back({i, pq.top().second});
            pq.pop();
        }
    }

    cout << res.size() << "\n";
    for (const auto& r : res) {
        cout << r.first << " " << r.second << "\n";
    }

    return 0;
}