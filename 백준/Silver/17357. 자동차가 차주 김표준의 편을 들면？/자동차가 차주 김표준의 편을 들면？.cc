#include <cmath>
#include <iostream>
using namespace std;

long long arr[1001];

int main() {
    cin.tie(0);
    cout.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int k = 1; k <= n; ++k) {
        long long mx = 0LL;
        int mx_place = -1;
        for (int i = 0; i < n - k + 1; ++i) {
            // i to i+k-1까지 순회.
            long long ex1 = 0LL, ex2 = 0LL;
            for (int j = 0; j < k; ++j) {
                ex1 += arr[i + j] * arr[i + j];
                ex2 += arr[i + j];
            }
            ex1 *= k;
            ex2 *= ex2;
            if (mx_place == -1 || mx < ex1 - ex2) {
                mx = ex1 - ex2;
                mx_place = i + 1;
            }
        }
        cout << mx_place << '\n';
    }
}