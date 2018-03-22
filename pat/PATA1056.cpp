//
//  PATA1056.cpp
//  pat
//
//  Created by 帝君 on 2018/2/26.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_NUMBER 1000

static struct play{
    int weight,rank;
}mouse[MAX_NUMBER];

int PATA1056(void){
    
    freopen("input.txt", "r", stdin);
    int np, ng;
    scanf("%d%d", &np, &ng);
    
    for(int i = 0; i< np;i++){
        scanf("%d", &mouse[i].weight);
    }
    
    int temp;
    queue<int> playing_order; // queue<struct play> playing;
    for(int i = 0 ; i< np; i++){
        scanf("%d", &temp);
        // playing.push(mouse[temp]); // it's also usefull
        playing_order.push(temp);
    }
    
    int temp_last_turn = np, group;
    while(playing_order.size()!= 1){ // enough abstrct things
        if(temp_last_turn%ng == 0){
            group = temp_last_turn/ng;
        }else{
            group = temp_last_turn/ng + 1;
        }
        
        for(int i = 0; i< group; i++){
            int k = playing_order.front(); // take the max weight and save
            for(int j = 0; j < ng; j++){
                if(i * ng + j >= temp_last_turn)break;
                int front = playing_order.front();
                if(mouse[front].weight > mouse[k].weight)
                    k = front;
                mouse[front].rank = group + 1; // here is important;
                playing_order.pop();
            }
            playing_order.push(k); // only push k // take the max weight and save
        }
        temp_last_turn = group;
    }
    mouse[playing_order.front()].rank = 1;
    
    for(int i = 0; i< np; i++){
        if(i!=0)printf(" ");
        printf("%d", mouse[i].rank);
    }
//    printf("\n");
    
    return 0;
} // AC
