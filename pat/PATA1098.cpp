//
//  PATA1098.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_N 101  // insertion sort or the heap sort

static int init_seq[MAX_N], N, mid_seq[MAX_N], heap_a[MAX_N];
static void insert_sort_once(int &i, vector<int> &seq){
        if(seq[i] < seq[i-1]){
            int temp = seq[i], j = i-1;
            while(seq[j] > temp && j>= 0){
                seq[j+1] = seq[j];
                j--;
            }
            seq[j+1] = temp;
        }
}

// big heap
static void upAdjust(int low, int high){
    int i =  high, j = high/2;
    while( j >= low){
        if( i%2!=0 && i-1 >= high && heap_a[i-1] > heap_a[i]){
            i = i-1;
        }
        if(heap_a[i] > heap_a[j]){
            swap(heap_a[i], heap_a[j]);
            i = j;
            j = i/2;
        }else{
            break;
        }
    }
}

// big heap
static void downAdjust(int low, int high){
    int i = low, j = low * 2; // i is the node to concern
    while(j <= high){
        if(j+1 <= high && heap_a[j+1] > heap_a[j]){
            j = j+1;
        }
        if(heap_a[i] < heap_a[j]){
            swap(heap_a[j], heap_a[i]);
            i = j;
            j = 2*i;
        }else{
            break;
        }
    }
}

static void downAdjust_mid(int low, int high){
    int i = low, j = low * 2; // i is the node to concern
    while(j <= high){
        if(j+1 <= high && mid_seq[j+1] > mid_seq[j]){
            j = j+1;
        }
        if(mid_seq[i] < mid_seq[j]){
            swap(mid_seq[j], mid_seq[i]);
            i = j;
            j = 2*i;
        }else{
            break;
        }
    }
}

static int heap_size = 0;
static void insert_heap(int value){
    heap_a[++heap_size] = value;
    upAdjust(1, heap_size);
}

static void build_heap(int data[], int n){ // 建堆不算一次排序
    for(int i = 1; i<= n; i++){
        insert_heap(data[i]);
    }
}

static void heap_sort_once(){
    swap(heap_a[1], heap_a[heap_size]);
    heap_size = heap_size - 1;
    downAdjust(1, heap_size);
}

static vector<int> mid_vec, ini_vec;
int PATA1098(void){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &init_seq[i]);
        ini_vec.push_back(init_seq[i]);
    }
    for(int i = 1; i <= N; i++){
        scanf("%d", &mid_seq[i]);
        mid_vec.push_back(mid_seq[i]);
    }

    int i = 1;
    while(i < N && ini_vec != mid_vec){
        insert_sort_once(i,ini_vec);
        i++;
    }
    
    if(i == N){
        printf("Heap Sort\n");
        int k = N;
        while (k >=0 && mid_seq[k] == k -1) {
            k--;
        }
        swap(mid_seq[1],mid_seq[k]);
        downAdjust_mid(1, k-1);
        for(int i = 1; i<= N; i++){
            if(i!= 1)printf(" ");
            printf("%d", mid_seq[i]);
        }
    }else{
        printf("Insertion Sort\n");
        insert_sort_once(i, ini_vec);
        for(vector<int>::iterator it = ini_vec.begin(); it!= ini_vec.end(); it++){
            if(it != ini_vec.begin())
                printf(" ");
            printf("%d", *it);
        }
    }
    
    return 0;
}
