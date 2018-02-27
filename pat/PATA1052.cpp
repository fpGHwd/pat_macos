//
//  PATA1052.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// 7surumi Rumi

#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_NUM 100000

static struct Node{
    int addr, value, flag, next; // why flag = 100000
}nodes[MAX_NUM];

static bool cmp(struct Node a, struct Node b){
    if(a.flag == 1 && b.flag == 1){ // also right here
        return a.value < b.value;
    }else{
        return a.flag > b.flag;
    }
//    if(a.flag == 0 || b.flag == 0){
//        return a.flag > b.flag;
//    }else{
//        return a.value < b.value;
//    }
}

int PATA1052(){
    freopen("input.txt", "r", stdin);
    int head, num;
    scanf("%d%d", &num, &head);
    int addr;
    for (int i= 0; i < num; i++) {
        scanf("%d", &addr);
        scanf("%d%d", &nodes[addr].value, &nodes[addr].next);
        nodes[addr].addr = addr;
    }
    
    int ele = head, valid = 0;
    while(ele != -1){
        valid++;
        nodes[ele].flag = 1;
        ele =  nodes[ele].next;
    }
    
    sort(nodes, nodes + MAX_NUM, cmp); // num -> max_num, critical
    
    if(valid == 0){
        printf("0 -1"); // when there is no elements
    }else{
        printf("%d %05d\n", valid, nodes[0].addr);
        for(int i = 0; i< valid; i++){
            if(i != valid -1){
                printf("%05d %d %05d", nodes[i].addr, nodes[i].value, nodes[i+1].addr);
            }else{
                printf("%05d %d -1", nodes[i].addr, nodes[i].value);
            }
            if(i!= valid -1)
                printf("\n");
        }
    }
    
    return 0;
}
