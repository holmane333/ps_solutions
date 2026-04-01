#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, t;
    vector<int> arr;
    unordered_map<int, int> m, m2;

    std::random_device rd;
    std::mt19937 gen(rd());

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> t;
        arr.push_back(t);
    }

    if (n == 1) {
        cout << 1;
        return 0;
    }

    std::uniform_int_distribution<> distrib(0, n - 1);
    int trial = 100, a, b, temp = 0, x = 0;

    for (int i = 0; i < trial; ++i) {
        a = distrib(gen);
        b = distrib(gen);
        
        while (a == b) {
            b = distrib(gen);
        }

        t = abs(arr[a] - arr[b]);
        for (int j = 2; j*j <= t; ++j) {
            if (t % j) continue;
            if (++m[j] > temp) {
                temp = m[j];
                x = j;
            }
            while (!(t % j)) {
                t /= j;
            }
        }
        if (t != 1) {
            if (++m[t] > temp) {
                temp = m[t];
                x = t;
            }
        }
    }

    vector<int> primes = {2};

    for (auto i : m)
    {
        primes.push_back(i.first);
    }

    int res = 0;
    for (int p : primes) {
        for (int i = 0; i < n; ++i) 
            res = max(res, ++m2[arr[i] % p]);
        for (int i = 0; i < n; ++i)
            m2[arr[i] % p] = 0;
    }
    cout << res;
}