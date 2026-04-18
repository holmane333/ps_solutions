#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n;
long long k;
long long a[MAXN], b[MAXN];

long long pref_a_max[MAXN], pref_a_min[MAXN], pref_b_max[MAXN], pref_b_min[MAXN];
long long suff_a_max[MAXN], suff_a_min[MAXN], suff_b_max[MAXN], suff_b_min[MAXN];

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        pref_a_max[i] = a[i];
        pref_a_min[i] = a[i];
        pref_b_max[i] = b[i];
        pref_b_min[i] = b[i];
        if (i > 0) {
            pref_a_max[i] = max(pref_a_max[i], pref_a_max[i-1]);
            pref_a_min[i] = min(pref_a_min[i], pref_a_min[i-1]);
            pref_b_max[i] = max(pref_b_max[i], pref_b_max[i-1]);
            pref_b_min[i] = min(pref_b_min[i], pref_b_min[i-1]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        suff_a_max[i] = a[i];
        suff_a_min[i] = a[i];
        suff_b_max[i] = b[i];
        suff_b_min[i] = b[i];
        if (i < n - 1) {
            suff_a_max[i] = max(suff_a_max[i], suff_a_max[i+1]);
            suff_a_min[i] = min(suff_a_min[i], suff_a_min[i+1]);
            suff_b_max[i] = max(suff_b_max[i], suff_b_max[i+1]);
            suff_b_min[i] = min(suff_b_min[i], suff_b_min[i+1]);
        }
    }

    long long H = pref_a_max[n-1] - pref_a_min[n-1];
    long long W = pref_b_max[n-1] - pref_b_min[n-1];
    long long max_area = 0;

    long long S = H + W + k;
    long long target = S / 2;
    for (long long t = target - 2; t <= target + 2; t++) {
        if (t >= H && t <= H + k) {
            long long t2 = S - t;
            max_area = max(max_area, (t + 1) * (t2 + 1));
        }
    }
    
    max_area = max(max_area, (H + 1) * (W + k + 1));
    max_area = max(max_area, (H + k + 1) * (W + 1));

    const long long INF = 2e18; 

    for (int i = 0; i < n; i++) {
        long long o_a_max = -INF, o_a_min = INF, o_b_max = -INF, o_b_min = INF;

        if (i > 0) {
            o_a_max = max(o_a_max, pref_a_max[i-1]);
            o_a_min = min(o_a_min, pref_a_min[i-1]);
            o_b_max = max(o_b_max, pref_b_max[i-1]);
            o_b_min = min(o_b_min, pref_b_min[i-1]);
        }
        if (i < n - 1) {
            o_a_max = max(o_a_max, suff_a_max[i+1]);
            o_a_min = min(o_a_min, suff_a_min[i+1]);
            o_b_max = max(o_b_max, suff_b_max[i+1]);
            o_b_min = min(o_b_min, suff_b_min[i+1]);
        }

        long long r = a[i];
        long long c = b[i];

        long long dr[] = {k, k, -k, -k};
        long long dc[] = {k, -k, k, -k};

        for (int dir = 0; dir < 4; dir++) {
            long long nr = r + dr[dir];
            long long nc = c + dc[dir];

            long long cur_a_max = max(nr, o_a_max);
            long long cur_a_min = min(nr, o_a_min);
            long long cur_b_max = max(nc, o_b_max);
            long long cur_b_min = min(nc, o_b_min);

            max_area = max(max_area, (cur_a_max - cur_a_min + 1) * (cur_b_max - cur_b_min + 1));
        }
    }

    cout << max_area << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}