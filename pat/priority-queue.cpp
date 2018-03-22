//
//  priority-queue.cpp
//  pat
//
//  Created by 帝君 on 2018/3/12.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

int pri_queue(void){
    priority_queue<int> q;
    q.push(4);
    q.push(1);
    q.push(5);
    q.push(100);
    printf("%d", q.top());
    
    printf("\n");
    priority_queue<int, vector<int>, greater<int>> q1;
    q1.push(4);
    q1.push(1);
    q1.push(5);
    q1.push(100);
    printf("%d", q1.top());
    
    if(!q1.empty())q1.top(); // 使用优先队列访问top的时候必须要先判断优先队列是否为空，否则会造成错误
    if(!q.empty())q.top();
    
    
    return 0;
}
