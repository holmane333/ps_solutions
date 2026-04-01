#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, r[30];
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    cin >> s;
    for (int i = 0; i < n / 2; ++i) {
        r[s[i] - 'a']++;
    }
    for (int i = n - 1; i >= n - n / 2; --i) {
        r[s[i] - 'a']++;
    }
    for (int i = 0; i < 27; ++i) {
        if (r[i] % 2) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
