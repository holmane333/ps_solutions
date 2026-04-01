#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;

struct Query
{
    int l, r, idx;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i];

    // 좌표 압축
    vector<int> t = l;
    sort(t.begin() + 1, t.end());
    t.erase(unique(t.begin() + 1, t.end()), t.end());

    auto compress = [&](int x)
    {
        return (int)(lower_bound(t.begin() + 1, t.end(), x) - t.begin());
    };

    for (int i = 1; i <= n; i++)
        l[i] = compress(l[i]);

    int sqrtn = (int)sqrt(n);

    vector<Query> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }

    sort(q.begin(), q.end(), [&](const Query &a, const Query &b)
         {
        int block_a = a.l / sqrtn, block_b = b.l / sqrtn;
        if (block_a == block_b) return a.r < b.r;
        return block_a < block_b; });

    vector<int> v(101010, 0);

    vector<int> res(m);
    int s = q[0].l, e = q[0].r, cnt = 0;

    for (int i = s; i <= e; i++)
    {
        if (v[l[i]] == 2)
            --cnt;
        ++v[l[i]];
        if (v[l[i]] == 2)
            ++cnt;
    }
    res[q[0].idx] = cnt;

    for (int i = 1; i < m; i++)
    {
        int a = q[i].l, b = q[i].r;
        for (int j = s - 1; j >= a; j--)
        {
            if (v[l[j]] == 2)
                --cnt;
            ++v[l[j]];
            if (v[l[j]] == 2)
                ++cnt;
        }
        for (int j = e + 1; j <= b; j++)
        {
            if (v[l[j]] == 2)
                --cnt;
            ++v[l[j]];
            if (v[l[j]] == 2)
                ++cnt;
        }
        for (int j = s; j < a; j++)
        {
            if (v[l[j]] == 2)
                --cnt;
            --v[l[j]];
            if (v[l[j]] == 2)
                ++cnt;
        }
        for (int j = e; j > b; j--)
        {
            if (v[l[j]] == 2)
                --cnt;
            --v[l[j]];
            if (v[l[j]] == 2)
                ++cnt;
        }
        res[q[i].idx] = cnt;
        s = a;
        e = b;
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";

    return 0;
}