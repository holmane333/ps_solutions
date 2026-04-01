#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, m, x, y;
	int red = 0, blue = 0, green = 0;
	string a;

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
	}
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> a;
		if (a[0] == 'R') ++red;
		else if (a[0] == 'G') ++green;
		else ++blue;
	}
	green %= 2;
	red += green;

	if (red > blue) cout << "jhnah917";
	else cout << "jhnan917";

	return 0;
}