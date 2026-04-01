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

    vector<int> cnt(101010, 0);
    vector<int> cnt_sqrt(n / sqrtn + 15, 0);
    vector<vector<int>> cnt_cnt(n / sqrtn + 15, vector<int>(n + 5, 0));

    auto dq_add = [&](int idx)
    {
        int tmp = l[idx] / sqrtn;
        cnt[l[idx]]++;
        cnt_sqrt[tmp] = max(cnt_sqrt[tmp], cnt[l[idx]]);
        cnt_cnt[tmp][cnt[l[idx]]]++;
    };

    auto dq_pop = [&](int idx)
    {
        int tmp = l[idx] / sqrtn;
        cnt_cnt[tmp][cnt[l[idx]]]--;
        if (!cnt_cnt[tmp][cnt[l[idx]]] && cnt_sqrt[tmp] == cnt[l[idx]])
        {
            cnt_sqrt[tmp]--;
        }
        cnt[l[idx]]--;
    };

    auto find_max = [&]()
    {
        int mi = *max_element(cnt_sqrt.begin(), cnt_sqrt.end());
        for (int i = (int)cnt_sqrt.size() - 1; i >= 0; i--)
        {
            if (mi != cnt_sqrt[i])
                continue;
            int a = i * sqrtn, b = i * sqrtn + sqrtn;
            for (int j = b; j >= a; j--)
            {
                if (j < (int)cnt.size() && cnt[j] == mi)
                    return j;
            }
        }
        return 0;
    };

    vector<int> res(m);
    int s = q[0].l, e = q[0].r;

    for (int i = s; i <= e; i++)
        dq_add(i);
    res[q[0].idx] = t[find_max()];

    for (int i = 1; i < m; i++)
    {
        int a = q[i].l, b = q[i].r;
        for (int j = s - 1; j >= a; j--)
            dq_add(j);
        for (int j = e + 1; j <= b; j++)
            dq_add(j);
        for (int j = s; j < a; j++)
            dq_pop(j);
        for (int j = e; j > b; j--)
            dq_pop(j);
        res[q[i].idx] = t[find_max()];
        s = a;
        e = b;
    }

    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";

    return 0;
}