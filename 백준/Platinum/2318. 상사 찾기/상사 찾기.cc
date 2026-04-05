#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 30005

struct Item {
    int id, salary, tenure;
    int salary_rank;
    int boss_idx;
    int child_count;
} items[MAXN];

int N, M;
int seg_tree[MAXN * 4];
vector<int> adj[MAXN];

bool cmp_tenure(const Item& a, const Item& b) {
    if (a.tenure != b.tenure) return a.tenure > b.tenure;
    return a.salary > b.salary;
}

void update(int node, int start, int end, int idx, int val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        seg_tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    seg_tree[node] = (seg_tree[node * 2] ? seg_tree[node * 2] : seg_tree[node * 2 + 1]);
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l || seg_tree[node] == 0) return 0;
    if (start == end) return seg_tree[node];
    int mid = (start + end) / 2;
    int res = query(node * 2, start, mid, l, r);
    return (res != 0) ? res : query(node * 2 + 1, mid + 1, end, l, r);
}

int get_subtree_size(int curr) {
    int count = 0;
    for (int next_node : adj[curr]) {
        count += 1 + get_subtree_size(next_node);
    }
    return items[curr].child_count = count;
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    vector<int> salaries;
    for (int i = 1; i <= N; i++) {
        scanf("%d %d %d", &items[i].id, &items[i].salary, &items[i].tenure);
        salaries.push_back(items[i].salary);
    }

    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()), salaries.end());

    for (int i = 1; i <= N; i++) {
        items[i].salary_rank = lower_bound(salaries.begin(), salaries.end(), items[i].salary) - salaries.begin() + 1;
    }

    sort(items + 1, items + N + 1, cmp_tenure);

    for (int i = 1; i <= N; i++) {
        int b_idx = query(1, 1, N, items[i].salary_rank + 1, N);
        if (b_idx != 0) {
            items[i].boss_idx = b_idx;
            adj[b_idx].push_back(i);
        }
        update(1, 1, N, items[i].salary_rank, i);
    }

    for (int i = 1; i <= N; i++) {
        if (items[i].boss_idx == 0) get_subtree_size(i);
    }

    for (int k = 0; k < M; k++) {
        int target_id;
        scanf("%d", &target_id);
        for (int i = 1; i <= N; i++) {
            if (items[i].id == target_id) {
                int b_id = (items[i].boss_idx == 0) ? 0 : items[items[i].boss_idx].id;
                printf("%d %d\n", b_id, items[i].child_count);
                break;
            }
        }
    }

    return 0;
}