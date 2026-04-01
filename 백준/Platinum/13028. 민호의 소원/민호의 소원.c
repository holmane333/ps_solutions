#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable : 4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

typedef struct pair
{
    long long a, b;
    int idx;
} pair;

long long n, m, ary[200020], visit[2000020], k, cnt, res[200020];
pair q[200020];

int cmp(const void *num1, const void *num2)
{
    pair a = *(pair *)num1;
    pair b = *(pair *)num2;
    if (a.a / k == b.a / k)
        return a.b - b.b;
    return a.a / k - b.a / k;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &ary[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld %lld", &(q[i].a), &(q[i].b));
        q[i].idx = i;
    }
    k = (int)sqrt(n);
    qsort(q + 1, m, sizeof(pair), cmp);

    long long s = q[1].a, e = q[1].b;
    for (int i = q[1].a; i <= q[1].b; ++i)
    {
        ++visit[ary[i]];
        if (visit[ary[i]] == 3)
            ++cnt;
    }
    res[q[1].idx] = cnt;
    for (int i = 2; i <= m; ++i)
    {
        long long ns = q[i].a, ne = q[i].b;
        if (ns > e || ne < s)
        {
            memset(visit, 0, sizeof(visit));
            cnt = 0;
            for (int j = ns; j <= ne; ++j)
            {
                ++visit[ary[j]];
                if (visit[ary[j]] == 3)
                    ++cnt;
            }
        }
        else
        {
            if (ns < s)
            {
                for (int j = ns; j < s; ++j)
                {
                    ++visit[ary[j]];
                    if (visit[ary[j]] == 3)
                        ++cnt;
                }
            }
            else
            {
                for (int j = s; j < ns; ++j)
                {
                    if (visit[ary[j]] == 3)
                        --cnt;
                    --visit[ary[j]];
                }
            }

            if (ne < e)
            {
                for (int j = ne + 1; j <= e; ++j)
                {
                    if (visit[ary[j]] == 3)
                        --cnt;
                    --visit[ary[j]];
                }
            }
            else
            {
                for (int j = e + 1; j <= ne; ++j)
                {
                    ++visit[ary[j]];
                    if (visit[ary[j]] == 3)
                        ++cnt;
                }
            }
        }
        res[q[i].idx] = cnt;
        s = ns;
        e = ne;
    }
    for (int i = 1; i <= m; ++i)
    {
        printf("%lld\n", res[i]);
    }
    return 0;
}