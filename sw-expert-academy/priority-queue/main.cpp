#include <stdio.h>
#include "main.h"

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit(void) {
    heapSize = 0;
}

int heapPush(int value) {
    if (heapSize + 1 > MAX_SIZE) {
        printf("queue is full!");
        return 0;
    }

    heap[heapSize] = value;

    int current = heapSize;
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;
        current = (current - 1) / 2;
    }

    heapSize = heapSize + 1;

    return 1;
}

int heapPop(int *value) {
    if (heapSize <= 0) {
        return -1;
    }

    *value = heap[0];
    heapSize = heapSize - 1;

    heap[0] = heap[heapSize];

    int current = 0;
    while (current * 2 + 1 < heapSize) {
        int child;
        if (current * 2 + 2 == heapSize) {
            child = current * 2 + 1;
        }
        else {
            child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
        }

        if (heap[current] < heap[child]) {
            break;
        }

        int temp = heap[current];
        heap[current] = heap[child];
        heap[child] = temp;

        current = child;
    }
    return 1;
}

