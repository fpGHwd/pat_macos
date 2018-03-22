//
//  floyd.cpp
//  pat
//
//  Created by 帝君 on 2018/3/4.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

static const int INF = 1e9, MAXV = 200;
static int m, n, G[MAXV][MAXV];

static void Floyd(void){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(G[i][k] != INF && G[k][j] != INF && G[i][k] + G[k][j] < G[i][j]){ // how to get code by the equation of the floyd algorithm
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

int floyd(void){
    freopen("input.txt", "r", stdin);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d%d", &n, &m);
    for(int i =0; i< n; i++){
        G[i][i] = 0;
    }
    int u,v,w;
    for(int i = 0; i< m; i++){
        scanf("%d%d%d", &u, &v,&w);
        G[u][v] = w;
//        G[v][v] = w;
    }
    
    Floyd();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(G[i][j] == INF)
                printf("N ");
            else
                printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

/*
6 8
0 1 1
0 3 4
0 4 4
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3

output:
0 1 5 3 4 6
N 0 4 2 5 5
N N 0 N N 1
N N 2 0 3 3
N N N N 0 3
N N N N N 0
*/
