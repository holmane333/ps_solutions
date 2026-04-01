#include <stdio.h>
#pragma warning(disable:4996)
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
typedef struct node{
  long long data, lazy;
}node;

int n, m;
long long ary[1000002];
node seg_tree[2097154];

long long abs(long long a) {
  return a > 0 ? a : -a;
}

long long init(int node, int start, int end) {
  if (start == end)
    return seg_tree[node].data = ary[start];
  else
    return seg_tree[node].data = init(node * 2, start, (start + end) / 2) ^ init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int index, long long diff) {
  if (index < start || index > end) return;
  seg_tree[node].data = seg_tree[node].data ^ diff;
  if (start != end) {
    update(node * 2, start, (start + end) / 2, index, diff);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
  }
}

void rangeupdate(int node, int start, int end, int left, int right, long long diff) {
  if (seg_tree[node].lazy != 0) {
    seg_tree[node].data ^= seg_tree[node].lazy * ((end - start + 1) % 2);
    if (start != end) {
      seg_tree[node * 2].lazy ^= seg_tree[node].lazy;
      seg_tree[node * 2 + 1].lazy ^= seg_tree[node].lazy;
    }
    seg_tree[node].lazy = 0;
  }
  if (right < start || left > end) return;
  else if (left <= start && end <= right) {
    seg_tree[node].data ^= diff * ((end - start + 1) % 2);
    if (start != end) {
      seg_tree[node * 2].lazy ^= diff;
      seg_tree[node * 2 + 1].lazy ^= diff;
    }
  }
  else {
    rangeupdate(node * 2, start, (start + end) / 2, left, right, diff);
    rangeupdate(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff);
    seg_tree[node].data = seg_tree[node * 2].data ^ seg_tree[node * 2 + 1].data;
  }
}
 
long long sum(int node, int start, int end, int left, int right) {
  if (seg_tree[node].lazy != 0) {
    seg_tree[node].data ^= seg_tree[node].lazy * ((end - start + 1) % 2);
    if (start != end) {
      seg_tree[node * 2].lazy ^= seg_tree[node].lazy;
      seg_tree[node * 2 + 1].lazy ^= seg_tree[node].lazy;
    }
    seg_tree[node].lazy = 0;
  }
  if (left > end || right < start) return 0LL;
  if (left <= start && end <= right) return seg_tree[node].data;
  return sum(node * 2, start, (start + end) / 2, left, right) ^ sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &ary[i]);
  }
  scanf("%d", &m);
  init(1, 1, n);
  for (int i = 0; i < m; i++) {
    int a, t;
    scanf("%d", &a);
    if (a == 1) {
      int b, c;
      long long d;
      scanf("%d %d %lld", &b, &c, &d);
      b++; c++;
      if (b > c) swap(b, c, t);
      rangeupdate(1, 1, n, b, c, d);
    }
    else {
      int b, c;
      scanf("%d %d", &b, &c);
      b++; c++;
      if (b > c) swap(b, c, t);
      printf("%lld\n", sum(1, 1, n, b, c));
    }
  }
  
  
  return 0;
}
