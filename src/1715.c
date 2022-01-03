#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

#define MAX_ELEMENT 1000001

typedef struct{
  long long int key;
} element;

typedef struct{
  element heap[MAX_ELEMENT];
  int heap_size;
} HeapType;


void insert_min_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	
	while((i != 1) && (item.key < h->heap[i/2].key)){
    	h->heap[i] = h->heap[i/2];
    	i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType *h){
	int parent, child;
	element item, temp;

	item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
	temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
	parent = 1;
	child = 2;

	while(child <= h->heap_size){
    	if( (child < h->heap_size) && ((h->heap[child].key) > h->heap[child+1].key) ){
			child++;
    	}
    	if( temp.key <= h->heap[child].key ){
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
	int n;
	scanf("%d", &n);
	long long int data;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &data);
		element input;
		input.key = data;
		insert_min_heap(&heap1, input);
	}
	long long int res = 0;
	while(heap1.heap_size != 1) {
		element e1, e2;
		e1 = delete_min_heap(&heap1);
		e2 = delete_min_heap(&heap1);
		res += e1.key + e2.key;
		e1.key += e2.key;
		insert_min_heap(&heap1, e1);
	}
	/*element e1 = delete_min_heap(&heap1);
	res += e1.key;*/
	printf("%lld\n", res);
	
	return 0;
}