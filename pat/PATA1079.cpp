//
//  PATA1079.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector> // critical: vector to save

using namespace std;

#define MEMBERS 100001
static double sales[MEMBERS]; // float -> double
static int N;
static double r, P; // r is percentage, P is root price

static struct Node{
    double amount; // int -> double
    vector<int> children;
}chain_node[MEMBERS];

// 各种抽象/改编已有的经典的函数
static void supply_chain(int root, double price){ // price is root price // float -> double and AC  	
    if(chain_node[root].children.size() == 0){
        sales[root] = price * chain_node[root].amount;
        return;
    }
    for(vector<int>::iterator it = chain_node[root].children.begin(); it != chain_node[root].children.end(); it++){
        supply_chain(*it, (r * 1.0 /100 + 1) * price);
    }
} // turn price to depth may increase the preciousity

int PATA1079(void){
    freopen("input.txt", "r", stdin);
    scanf("%d %lf %lf", &N, &P, &r);
    for(int i = 0; i< N; i++){
        int flag, temp;
        scanf("%d", &flag);
        if(flag == 0){
            scanf("%d", &temp);
            chain_node[i].amount = temp;
        }else{
            for(int j = 0; j < flag; j++){
                scanf("%d", &temp);
                chain_node[i].children.push_back(temp);
            }
        }
    }
    supply_chain(0, P);
    double amount = 0;
    for(int i = 0; i < N; i++){
        amount += sales[i];
    }
    printf("%.1f", amount); // %.1f
    
    return 0;
} // change TYPE and AC, 玄学AC
