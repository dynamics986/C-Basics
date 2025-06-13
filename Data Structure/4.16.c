#include <stdio.h>
#include <stdlib.h>

/* kth Largest Element in a Sorted Matrix */

struct Heap {
	int capacity;
	int size;
	int* elements;
};

typedef struct Heap MaxHeap;

MaxHeap* createMaxHeap(int capacity){
	MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
	heap->elements = (int*)malloc(capacity * sizeof(int));
	heap->capacity = capacity;
	heap->size = 0;
	return heap;
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify (MaxHeap* heap, int idx){
	// array starts from 0
	int largest = idx;
	int left  = 2*idx+1;
	int right = 2*idx+2;
	
	if (left < heap->size && heap->elements[left]>heap->elements[largest])
		largest = left;
	
	if (right < heap->size && heap->elements[right]>heap->elements[largest])
		largest = right;
	
	if (largest!=idx){
		swap(&heap->elements[idx],&heap->elements[largest]);
		heapify(heap,largest);
	}
}

void insertHeap(MaxHeap* heap, int element){
	if (heap->size <heap->capacity){
		heap->elements[ heap->size ++ ] = element;
		for (int i=heap->size/2 - 1;i>=0; i--) // i-- not i++
			heapify(heap, i);
	}
	else if (element < heap->elements[0]){
		heap->elements[0] = element; //k-th smallest is the root
		heapify(heap,0);
	}
}

int getResult(MaxHeap* heap){
	return heap->elements[0];
}

int main(){
	int N;
	scanf("%d",&N);
	for (int i=0; i<N; i++){
		int n,k;
		scanf("%d %d",&n,&k);
		int capacity = n*n-k+1;
		MaxHeap* heap=createMaxHeap(capacity);
		int element;
		for (int j=0;j<n*n;j++){
			scanf("%d",&element);
			insertHeap(heap,element);
		}
		printf("%d\n",heap->elements[0]);
		free(heap->elements);
		free(heap);
	}
	return 0;
}



