//
//  PATA1097.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_NUM 100000

static struct Node{
    int addr, value, next, flag, order;
}nodes[MAX_NUM];
static int hashTable[MAX_NUM] ={0};

static bool cmp(struct Node a, struct Node b){
    if(a.flag != b.flag){
        return a.flag > b.flag;
    }else{
        if(a.flag != 0){
            return a.order < b.order;
        }else{
            return a.flag > b.flag;
        }
    }
}

int PATA1097(void){
    freopen("input.txt", "r", stdin);
    int head, n;
    scanf("%d%d", &head, &n);
    
    int addr;
    for(int i = 0; i< n; i++){
        scanf("%d", &addr);
        scanf("%d%d", &nodes[addr].value, &nodes[addr].next);
        nodes[addr].addr = addr;
    }
    
    int ele = head, valid = 0, removed = 0, remaining = 0;
    while(ele != -1){
        valid++;
        nodes[ele].flag = 2;
        if(hashTable[abs(nodes[ele].value)]){
            nodes[ele].order = removed;
            removed++;
            nodes[ele].flag = 1;
        }else{
            nodes[ele].order = remaining; // a "valid" order is enough without using removed and remaining
            remaining++;
            hashTable[abs(nodes[ele].value)] = 1;
            nodes[ele].flag = 2;
        }
        ele = nodes[ele].next;
    }
    
    sort(nodes, nodes+MAX_NUM, cmp);
    
    for(int i = 0; i< remaining; i++){
        if(i!= remaining -1)
            printf("%05d %d %05d\n", nodes[i].addr, nodes[i].value, nodes[i+1].addr);
        else{
            printf("%05d %d -1", nodes[i].addr, nodes[i].value);
        }
    }
    
    printf("\n");
    
    for(int i = 0; i< removed; i++){
        if(i!= removed-1){
            printf("%05d %d %05d\n", nodes[i+remaining].addr, nodes[i+remaining].value, nodes[i+remaining+1].addr);
        }else{
            printf("%05d %d -1", nodes[i+remaining].addr, nodes[i+remaining].value);
        }
    }
    
    return 0;
} // 20180227 1530 // AC

