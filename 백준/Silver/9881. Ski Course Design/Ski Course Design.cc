#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, res = 1e9 + 7, t, min_v = 101, max_v = -1;
    vector<int> arr;
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
        min_v = min(min_v, t);
        max_v = max(max_v, t);
    }

    for (int i = min_v; i <= max_v - 17; ++i) {
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j]< i) {
                temp += (i - arr[j]) * (i - arr[j]);
            }
            else if (arr[j] > i + 17) {
                temp += (arr[j] - i - 17) * (arr[j] - i - 17);
            }
        }
        res = min(res, temp);
    }

    if (res == 1e9 + 7) res = 0;


    cout << res;

    return 0;
}