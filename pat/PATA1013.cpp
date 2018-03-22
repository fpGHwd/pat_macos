//
//  PATA1013.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_N 1000

static vector<int> adjacents[MAX_N];

static int visited[MAX_N] = {0};
static void DFS(int u){
    visited[u] = 1;
    for(vector<int>::iterator it = adjacents[u].begin(); it != adjacents[u].end(); it++){
        if(visited[*it] == 0){
            DFS(*it);
        }
    }
}

static int travel(int n){
    int t = 0;
    for(int i = 1; i <= n; i++){ //     for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            DFS(i);
            t++;
        }
    }
    return t;
}

int PATA1013(){
    freopen("input.txt", "r", stdin);
    int N, M, K; // cities, highways, to be checked
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i< M; i++){
        int a,b;
        scanf("%d%d", &a, &b);
        adjacents[a].push_back(b);
        adjacents[b].push_back(a);
    }
    
    for(int i = 0; i< K; i++){
        for(int j = 1; j <= N; j++){
            visited[j] = 0;
        }
        int ct;
        scanf("%d", &ct); // city index is 1,2,3
        visited[ct] = 1; // occupied city is same as visited
        if(i != 0)printf("\n");
        printf("%d", travel(N) - 1); // the connected blocks - 1
    }
    
    return 0;
} // 20180302 0852 AC the sample
