#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Max-heap implementation
typedef struct {
    int capacity;
    int size;
    int *arr;
} MaxHeap;

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->arr = (int*)malloc(capacity * sizeof(int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MaxHeap* heap, int idx) {
    // array starts from 0
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

void insertHeap(MaxHeap* heap, int element) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size++] = element;
        for (int i = heap->size / 2 - 1; i >= 0; i--)
            heapify(heap, i);
    } // heapis not full
    else if (element < heap->arr[0]) {
        heap->arr[0] = element;
        heapify(heap, 0);
    } // heap is full
}

int getKthSmallest(MaxHeap* heap) {
    return heap->arr[0];
}

int deleteHeap(MaxHeap *h){
    int parent, child;
    int item, temp;
    if (h->size == 0){
        printf("The heap is empty\n");
        exit(1);
    }
    // save value of the minimum element for return
    item = h->arr[0];
    
    //use last element in heap to adjust heap
    temp = h->arr[h->size - 1];
    h->size--;
    parent = 0;
    child = 1;

    while (child <= (h->size - 1)){
        // find the smaller child of the current parent
        if ( (child < (h->size - 1)) &&
        (h->arr[child] > h->arr[child+1] ) )
            child++;
        if (temp<=h->arr[child]) break;
        // move to the next lower level
        h->arr[parent] = h->arr[child];
        parent = child;
        child = 2*child + 1;
    }
    h->arr[parent] = temp;
    return item;
}

int main() {
    int k; // k is the capacity of our heap
    scanf("%d", &k);
    clock_t start = clock();
    MaxHeap* heap = createMaxHeap(k);

    char oper;
    int input;
    while (scanf(" %c", &oper) == 1) {
        if (oper == 'I') {
            scanf("%d", &input);
            insertHeap(heap, input);
        } else if (oper == 'O') {
            if (heap->size >= k)
                printf("%d\n", getKthSmallest(heap));
        } else if (oper == 'S') {
            break;
        }
    }
    free(heap->arr);
    free(heap);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}