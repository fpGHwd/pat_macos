//
//  PATA1090.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

#define MEMBERS 100001
static double details_price[MEMBERS];
static int N;
static double r, P;

static struct Node{
    double amount;
    vector<int> children;
}chain_node[MEMBERS];

static void supply_chain(int root, double price){
    if(chain_node[root].children.size() == 0){
        details_price[root] = price;
        return;
    }
    for(vector<int>::iterator it = chain_node[root].children.begin(); it != chain_node[root].children.end(); it++){
        supply_chain(*it, (r * 1.0 /100 + 1) * price); // not use depth so not confused
    }
}

// sfbj DFS
//int n, maxDepth = 0, num = 0;
//static void DFS(int index, int depth){
//    if(chain_node[index].children.size() == 0){
//        if(depth > maxDepth){
//            maxDepth = depth;
//            num = 1;
//        }else{
//            num++;
//        }
//        return;
//    }
//    for(vector<int>::iterator it = chain_node[index].children.begin(); it != chain_node[index].children.end(); it++){
//        DFS(*it, depth+1);
//    }
//}

int PATA1090(void){
    freopen("input.txt", "r", stdin);
    scanf("%d %lf %lf", &N, &P, &r);
    int root = 0;
    for(int i = 0; i< N; i++){
        int temp;
        scanf("%d", &temp);
        if(temp == -1)
            root = i;
        else
            chain_node[temp].children.push_back(i);
    }
    supply_chain(root, P);
    double max_amount = -1;
    int max_count = 0;
    for(int i = 0; i < N; i++){
        if(details_price[i] > max_amount)
            max_amount = details_price[i];
    }
    
    int i = 0;
    while( i< N){
        if(details_price[i] == max_amount){
            max_count++;
        }
        i++;
    }
    printf("%.2lf %d", max_amount, max_count);
    
    return 0;
} // 20180228 0836 // AC
