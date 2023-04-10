#if !defined(HEAPS)
#define HEAPS

#include <stdlib.h>
#include <stdint.h>

typedef struct Heap {
    int* heap;
    int size;
    int capacity;
} Heap;

Heap* create(int capacity);
void swap(int* a, int* b);
void insert(Heap* heap, int value);
void heapify_down(Heap* heap, int index);
int extract_max(Heap* heap);
void destroy(Heap* heap);

#endif

