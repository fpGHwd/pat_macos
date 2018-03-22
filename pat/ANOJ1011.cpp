
//
//  ANOJ1011.cpp
//  pat
//
//  Created by 帝君 on 2018/3/12.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

static const int max_n = 1000;
static int N, M;
//priority_queue<int, vector<int>, greater<int>> adj[max_n];
static int vis[max_n] = {0};
static vector<int> path, adj[max_n], temp;

static void DFS(int u){ // abstract a n used as a depth and path likewise
    temp.push_back(u);
    if(temp.size() > path.size()){
        path = temp;
    }else{
        vis[u] = 1;
        for(auto it = adj[u].begin(); it != adj[u].end(); it++)
            if(vis[u] == 0)
                DFS(*it);
        vis[u] = 0;
    }
    temp.pop_back();
}

int ANOJ1011(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    int u,v, start = N;
    for(int i = 0; i< N; i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        if(u < start)start = u;
    }
    
    DFS(start);
    
    if(path.size() == N){
        printf("YES");
        for(int i = 0; i < path.size(); i++){
            if(i!= 0)printf(" ");
            else printf("\n");
            printf("%d", path[i]);
        }
    }else{
        printf("NO\n%d", N - (int)path.size());
    }
    
    return 0;
}
