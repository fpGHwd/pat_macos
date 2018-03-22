//
//  PATA1076.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

static const int maxn = 1010;
static int N,L;
static vector<int> Adj[maxn];
static int forward_[maxn] = {0}, count_ = 0;

static void DFS(int u, int depth){
    forward_[u]++; // forwards is just visited, but contains somethig more different
    count_++;
    for(int i = 0; i < Adj[u].size(); i++){
        int v = Adj[u][i];
        if(forward_[v] == 0 && depth < L){ // depth <= L -> depth < L then AC the sample
            DFS(v, depth+1);
        }
    }
}

int PATA1076(void){
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &L);
    int num;
    for(int i = 1; i <= N; i++){
        scanf("%d", &num);
        int followee;
        for(int j = 0; j < num; j++){
            scanf("%d", &followee);
            Adj[followee].push_back(i);
        }
    }
    
    scanf("%d", &num);
    int query, depth; // arguments forwards only can handdle arguments like depth, because it has the same format // location = structure = format
    for(int i = 0; i< num; i++){
        scanf("%d", &query);
        depth = 0;
        for(int j = 0; j<N; j++){
            forward_[j] = 0;
        }
        count_ = 0;
        DFS(query, depth);
        if(i!= 0)
            printf("\n");
        printf("%d", count_-1);
    }
    
    return 0;
} // 20180302 1734 AC the sample
