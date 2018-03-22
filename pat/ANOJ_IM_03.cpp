//
//  ANOJ_IM_03.cpp
//  pat
//
//  Created by 帝君 on 2018/3/12.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

static const int MAX_N = 1010, INF = 1E9;
static int N, M, G[MAX_N][MAX_N];

static void dijkstra(int u){
    return;
}

int ANOJ_IM_03(void){
    freopen("input.txt", "r", stdin);
    fill(G[0], G[0] + MAX_N * MAX_N, INF);
    scanf("%d%d", &N, &M);
    int u,v,w;
    for(int i = 0; i< M; i++){
        scanf("%d%d%d",&u,&v,&w);
        G[u][v] = w;
    }
//    dijkstra()
    
    return 0;
}
