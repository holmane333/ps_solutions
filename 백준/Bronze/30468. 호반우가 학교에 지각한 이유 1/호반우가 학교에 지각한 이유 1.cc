#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a, b, c, d, n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> a >> b >> c >> d >> n;
    
    a = a + b + c + d;
    n *= 4;
    cout << max(0, n - a);

    return 0;
}
