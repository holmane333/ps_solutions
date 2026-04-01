#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll a, b;
    vector<p> arr, arr2;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        if (a <= b)
            arr.push_back(make_pair(a, b));
        else
            arr2.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end(), [](const p &x, const p &y)
         {
        if (x.first == y.first) return x.second > y.second;
        return x.first < y.first; });

    sort(arr2.begin(), arr2.end(), [](const p &x, const p &y)
         {
        if (x.second == y.second) return x.first < y.first;
        return x.second > y.second; });

    ll res = 0, res2 = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (res < arr[i].first)
        {
            res2 += arr[i].first - res;
            res = arr[i].first;
        }
        res += arr[i].second - arr[i].first;
    }

    for (int i = 0; i < arr2.size(); ++i)
    {
        if (res < arr2[i].first)
        {
            res2 += arr2[i].first - res;
            res = arr2[i].first;
        }
        res += arr2[i].second - arr2[i].first;
    }

    cout << res2;
}