//
//  heap.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

// heap = insert + pop
// insert = build/create heap + upAdjust
// pop = delete pop + downAdjust

const int maxn = 100;
static int heap[maxn +1], heap_size = 0;

static void downAdjust(int low, int high){ // low - operation, high - heap or heap margin
    int i = low, j = 2*i;
    while( j <= high){
        if(j+1 <= high)
            if(heap[j+1] > heap[j]) // add a condition of j+1 < high
                j = j+1;
        if(heap[i] < heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = 2*i;
        }else{
            break; // break here
        }
    }
}// can abstract low to the element and elements behind(in the term of heap index) need to adjust
// iteration is a farer with real than recursion

static void createHeap(int n){
    for(int i = n /2; i >=1; i--){ // i >= 1 when use [1,n] as the heap space
        downAdjust(i, n);
    }
}

static void init_heap(int data[], int n){
    heap_size = n;
    for(int i = 1; i <= n; i++){
        heap[i] = data[i-1]; // data[i] -> data[i-1]
    }
}

static int popHeap(void){
    int value = heap[1];
    heap[1] = heap[heap_size--];
    downAdjust(1, heap_size);
    return value;
}

static void upAdjust(int low, int high){ // when upAdjust, it must e a heap, so condition is embedded in the heap structrue
    int i = high, j = high /2;
    while( j >= low){
        if(i%2 != 0 && heap[i-1] > heap[i]){ // i == odd is equal to statement that i has a side-brother
            i = i-1;
        }
        if(heap[i] > heap[j]){
            swap(heap[i], heap[j]);
            i = j;
            j = j/2; // j = i/2
        }else{
            break;
        }
    }
}

static bool insertHeap(int value){
    if(heap_size == maxn)
        return false;
    else{
        heap[++heap_size] = value;
        upAdjust(1, heap_size);
        return true;
    }
}

static void printHeap(void){
    int count_printff = 0;
    for(int i = 1; i<= heap_size; i++){
        if(count_printff != 0)
            printf(" ");
        count_printff++;
        printf("%d", heap[i]);
//        if(count_printff != 0)
//            printf(" ");
//        count_printff++;
//        printf("%d", popHeap());
    }
}

static int data_size;
static void heapSort(){ // seperate function
//    createHeap();
    for(int i = data_size; i >= 1; i--){
        swap(heap[i], heap[1]);
        downAdjust(1, i-1);
    }
}

int heap_(void){
    int data[] ={85, 55, 82, 57, 68, 92, 99, 98, 66,56}, len = 10;
    init_heap(data, len);
    createHeap(len);
    printHeap(); // 99 98 92 66 68 85 82 57 55 56
    insertHeap(100);// add a element
    printf("\n");
    printHeap(); // 100 99 92 66 98 85 82 57 55 56 68
    
    return 0;
}
// transform problems or real to (data)structure or space // plus method and minus method are all the method from abstraction/abstract(never mind)
// so teaching is corrent abstract and seperate the proper structure
