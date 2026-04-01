#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l, totv, maxv;
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> l;
    totv = 0;
    maxv = 0;
    int prev, cnt;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        prev = cnt = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] - '0' && prev) continue;
            if (s[j] - '0' && !prev) {
                prev = 1;
                ++cnt;
            }
            if (!(s[j] - '0')) prev = 0;
        }
        if (cnt == maxv) totv++;
        else if (cnt > maxv) {
            maxv = cnt;
            totv = 1;
        }
    }

    cout << maxv << " " << totv;


    return 0;
}
