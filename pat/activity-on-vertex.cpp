//
//  activity-on-vertex.cpp
//  pat
//
//  Created by 帝君 on 2018/3/5.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// AOV -> AOE, 另外当判断AOE有超过一个源点和一个汇点的时候，需要添加一个超级源点和一个超级汇点以保护代码(的模块性)

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct edge{
    int u,v,w;
};

static const int MAXV = 1010;
static int N, M, /*G[MAXV][MAXV],*/ inDegree[MAXV] = {0}, ve[MAXV] = {0}, vl[MAXV] = {0};
static vector<edge> G[MAXV];

static stack<int> topOrder; // 获得反向序列以计算late[i]
static bool topologicalSort(){
    queue<int> q;
    for(int i = 0; i< N; i++){
        if(inDegree[i] == 0){
            q.push(i); // q.push(inDegree[i]) -> q.push(i)；
        }
    }
    
    int u;
    while(!q.empty()){
        u = q.front();
        topOrder.push(u);
        q.pop();
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v;
            if(ve[u] + G[u][i].w > ve[v])
                ve[v] = ve[u]+ G[u][i].w;
            inDegree[v]--;
            if(inDegree[v] == 0)
                q.push(v);
        }
//         G[u].clear();
    }
    
    if(topOrder.size() == N)
        return true;
    else
        return false;
}

static int count_key = 0;
static int CriticalPath(){
    memset(ve, 0, sizeof(ve));
    if(topologicalSort() == false)
        return -1;
        
    fill(vl, vl+MAXV, ve[N-1]);
    while(!topOrder.empty()){
        int u = topOrder.top(); // 拆分两个操作的意义
        topOrder.pop();
        for(int i = 0; i< G[u].size(); i++){
            int v = G[u][i].v;
            if(vl[u] > vl[v] - G[u][i].w){ // vl[u]要越小 // u/i/v意义
                vl[u] = vl[v] - G[u][i].w;
            }
        }
    }
    
    for(int u = 0; u < N; u++){
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i].v;
            int e = ve[u], l = vl[v] - G[u][i].w;
            if(e == l){
                if(count_key != 0)printf("\n");
                printf("%d->%d", u, v);
                count_key++;
            }
        }
    }
    return ve[N-1];
}

int AOE(void){
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    int u, v, w;
    for(int i = 0; i < M; i++){
        scanf("%d%d%d",&u, &v, &w);
        edge e;
        e.u = u;
        e.v = v;
        e.w = w;
        G[u].push_back(e);
        inDegree[v]++;
    }
    
    int w_sum = CriticalPath();
    printf("\nweight of critical path: %d", w_sum);
    
    return 0;
}
