#include <stdio.h>
#include <stdlib.h>
#include "heaps.h"

Heap* create(int capacity) {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->heap = (int*) malloc(sizeof(int) * (capacity + 1)); // +1 for 1-based indexing
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->heap = (int*)realloc(heap->heap, sizeof(int) * (heap->capacity + 1));
    }
    heap->size++;
    heap->heap[heap->size] = value;
    int index = heap->size;
    while (index > 1 && heap->heap[index] > heap->heap[index/2]) {
        swap(&heap->heap[index], &heap->heap[index/2]);
        index /= 2;
    }
}

void heapify_down(Heap* heap, int index) {
    while (2*index <= heap->size) {
        int left = 2*index;
        int right = 2*index + 1;
        int max_child = left;
        if (right <= heap->size && heap->heap[right] > heap->heap[left]) {
            max_child = right;
        }
        if (heap->heap[max_child] > heap->heap[index]) {
            swap(&heap->heap[index], &heap->heap[max_child]);
            index = max_child;
        } else {
            break;
        }
    }
}

int extract_max(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int max_value = heap->heap[1];
    heap->heap[1] = heap->heap[heap->size];
    heap->size--;
    heapify_down(heap, 1);
    return max_value;
}

void destroy(Heap* heap) {
    free(heap->heap);
    free(heap);
}

int main(){
    Heap* heap = create(5);
    insert(heap, 30);
    insert(heap, 20);
    insert(heap, 300);
    insert(heap, 40);
    insert(heap, 550);
    insert(heap, 60000);
    insert(heap, 77);
    insert(heap, 80);
    insert(heap, 90);
    insert(heap, 5);

    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));
    printf("Max value: %d\n", extract_max(heap));

}