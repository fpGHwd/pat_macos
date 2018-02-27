//
//  PATA1032.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>

static const int max_num = 100000;
static struct Node{
    int share = 0, next;
    char data;
}nodes[max_num];

int PATA1032(void){
    freopen("input.txt", "r", stdin);
    int head1, head2, num;
    scanf("%d%d%d", &head1, &head2, &num);
    // head1 stands for word1, head2 stands for word2, while num contains details or abstract info about them
    
    int addr;
    for(int i = 0; i < num; i++){
        scanf("%d ", &addr);
        scanf("%c %d", &nodes[addr].data, &nodes[addr].next); // here two blanks is critical
    }
    
    int ele = head1; // ele = ele_addr
    while(ele != -1){
        nodes[ele].share = 1;
        ele = nodes[ele].next;
    }
    
    ele = head2;
    while(ele != -1 && nodes[ele].share == 0){
        ele = nodes[ele].next;
    }
    
    if(ele == -1){
        printf("-1");
    }else{
        printf("%05d", ele);
    }
    // output the postion, also the point, so just find the point // if no, output -1 instead
    
    return 0;
}
