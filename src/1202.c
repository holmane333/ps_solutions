#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

#define MAX_ELEMENT 300001

typedef struct{
  int m;
  int v;
} element;

typedef struct{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;

int static compare (const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int static compare2 (const void* first, const void* second) {
	int* pa = (int*)first;
	int* pb = (int*)second;
    if (pa[0] > pb[0])
        return 1;
    else if (pa[0] < pb[0])
        return -1;
    else {
    	if (pa[1] > pb[1])
        	return 1;
    	else if (pa[1] < pb[1])
        	return -1;
        else
        	return 0;
    }
}

void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	
	while((i != 1) && (item.v > h->heap[i/2].v)){
    	h->heap[i] = h->heap[i/2];
    	i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h){
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while(child <= h->heap_size){
    	if( (child < h->heap_size) && ((h->heap[child].v) < h->heap[child+1].v) ){
			child++;
    	}
    	if( temp.v >= h->heap[child].v ){
    		break;
    	}
    	h->heap[parent] = h->heap[child];
    	parent = child;
    	child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	HeapType heap1;
	heap1.heap_size = 0;
	int n, k;
	scanf("%d %d", &n, &k);
	int pair[300001][2];
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &pair[i][0], &pair[i][1]);
	}
	int ary[300001];
	long long int res = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &ary[i]);
	}
	qsort(ary, k, sizeof(int), compare);
	qsort(pair, n, sizeof(int) * 2, compare2);
	int pair_cnt = 0;
	for (int ary_cnt = 0; ary_cnt < k; ary_cnt++) {
		while (pair_cnt < n && pair[pair_cnt][0] <= ary[ary_cnt]) {
			element input;
			input.m = pair[pair_cnt][0];
			input.v = pair[pair_cnt++][1];
			insert_max_heap(&heap1, input);
		}
		if (heap1.heap_size != 0) {
			element new1 = delete_max_heap(&heap1);
			res += new1.v;
		}
	}
	
	printf("%lld\n", res);
	return 0;
}