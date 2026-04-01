#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int t, n, m, a[1001], b[1001];
	vector<int> v1, v2;
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
	
	for (int i = 0; i < n; i++) {
        int sum = a[i];
        v1.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            v1.push_back(sum);
        }
    }
    
    for (int i = 0; i < m; i++) {
        int sum = b[i];
        v2.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            v2.push_back(sum);
        }
    }
    
	sort(v2.begin(), v2.end());
	
	long long int res = 0;
	for (auto item : v1)
    {
        int diff = t - item;
        auto ub = upper_bound(v2.begin(), v2.end(), diff);
        auto lb = lower_bound(v2.begin(), v2.end(), diff);
        res += (ub - lb);
    }
    cout << res;
    
	return 0;
}
