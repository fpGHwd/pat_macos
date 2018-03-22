//
//  PATA1074.cpp
//  pat
//
//  Created by 帝君 on 2018/2/26.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// "pao ma liuliu de tou a" is a seriours taste
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

static const int max_num = 100010;
static struct Node_PATA1074{ // Node -> Node_PATA1074 comment is not accurate
    int data, next, order, address;
}list[max_num];

static bool cmp(struct Node_PATA1074 a, struct Node_PATA1074 b){
    return a.order < b.order;
}

int PATA1074(void){ // cultivate abstract ability and use write and paint to strength it
    freopen("input.txt", "r", stdin);
    int head, num, k;
    scanf("%d%d%d", &head, &num, &k);
    
    for(int i = 0; i< max_num; i++){
        list[i].order = max_num; // need here
    }
    
    int address;
    for(int i = 0; i< num; i++){
        scanf("%d", &address);
        scanf("%d%d", &list[address].data, &list[address].next);
        list[address].address = address;
     }
    
    int valid = 0, work = head; // named "next" is not a good habit
    while(work != -1){
        list[work].order = valid++;
        work = list[work].next;
    }// valid nodes equals to valid // please do not confuse yourself
    
    sort(list, list + max_num, cmp);
    
    int reverse_block = valid / k; // block number need to be reversed
    for(int i = 0; i < reverse_block; i++){ // valid / k = group
        for(int j = (i+1) * k - 1; j >= i * k; j--){ // specify the element which is abstract to j;
            printf("%05d %d ", list[j].address, list[j].data);
            if(i <= reverse_block - 1 - 1){ // if not the last block
                if(j == i*k ){
                    printf("%05d\n", list[(i+2)*k -1].address);
                }else{
                    printf("%05d\n", list[j-1].address);
                }
            }else{ // this j is in the last block
                if(valid % k == 0){ // this j is in the last block and has no unreverse elements // valid / k == 0 -> valid % k == 0
                    if(j != i*k){
                        printf("%05d\n", list[j-1].address);
                    }else{
                        printf("-1");
                    }
                }else{ // this j is in the last block and has elements to be reversed
                    if(j != i*k){
                        printf("%05d\n", list[j-1].address);
                    }else{
                        printf("%05d\n", list[(i+1)*k].address);
                        // left elements
                        for(int p = (i+1)*k ; p < (i+1)*k + valid % k; p++){
                            if(p != (i+1)*k + valid % k -1)
                                printf("%05d %d %05d\n", list[p].address, list[p].data, list[p].next);
                            else
                                printf("%05d %d -1", list[p].address, list[p].data);
                        }
                    }
                }
                // to be commented
                /*
                if(j != i*k + 1){
                    printf("%05d\n", list[j-1].address);
                }else{
                    if(valid / k == 0){ // no not reverse left
                        printf("-1");
                    }else{ // has not reverse
                        for(int p = (i+1)*k ; p < (i+1)*k + valid % k; p++){
                            if(p != (i+1)*k + valid % k -1)
                                printf("%05d %d %05d\n", list[p].address, list[p].data, list[p].next);
                            else
                                printf("%05d %d -1", list[p].address, list[p].data);
                        }
                    }
                }
                 */
            }
        }
    }
    
    return 0;
}// not AC // AC @ 20180311 1531
