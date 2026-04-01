#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int ta[60][60], v[60][60], s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ta[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) {
            if (ta[i][j] > s) {
                v[i][j] = 1;
                s = ta[i][j];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) {
            if (ta[j][i] > s) {
                v[j][i] = 1;
                s = ta[j][i];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) {
            if (ta[n - i + 1][n - j + 1] > s) {
                v[n - i + 1][n - j + 1] = 1;
                s = ta[n - i + 1][n - j + 1];
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        s = 0;
        for (int j = 1; j <= n; ++j) {
            if (ta[n - j + 1][n - i + 1] > s) {
                v[n - j + 1][n - i + 1] = 1;
                s = ta[n - j + 1][n - i + 1];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (v[i][j]) ++res;
            //cout << v[i][j];
        }//cout << "\n";
    }

    cout << res << "\n";

    return 0;
}
