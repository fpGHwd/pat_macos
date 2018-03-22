//
//  PATA1030.cpp
//  pat
//
//  Created by 帝君 on 2018/3/2.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// graph
static const int MAXV = 500, INF = 1E9; // MAXV = 100 -> MAXV = 500 and AC @ 20180309 1913
static int G[MAXV][MAXV], N, M, S,D, cost[MAXV][MAXV]; // cost is the same with distance here

static int vis[MAXV], d[MAXV];
static vector<int> pre[MAXV];
static void dijkstra(int s){ // abstract is excllent, ease your brain power and detach complexity
    memset(vis, 0, sizeof(vis));
    fill(d, d+MAXV, INF);
    d[s] = 0; // start
    for(int i = 0; i< N; i++){
        int u = -1, min_d = INF;
        for(int j = 0; j< N; j++){
            if(vis[j] == 0 && d[j] < min_d){
                u = j;
                min_d = d[j];
            }
        }
        if(u == -1)return;
        vis[u] = 1;
        for(int v = 0; v< N; v++){
            if(vis[v] == 0 && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear(); // critical: understanding error // pre[u].clear(); -> pre[v].clear();
                    pre[v].push_back(u); //  pre[u].push_back(v); -> pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u); // pre[u].push_back(v); -> pre[v].push_back(u); // here AC
                }
            }
        }
    }
}

static int minCost = INF;
static vector<int> tempPath, path;
static void DFS(int v, int start){
    if(v == start){ // find the start
        tempPath.push_back(v);
        int c = 0;
        for(int i = (int)tempPath.size() -1; i > 0; i--){ // cost not node weight
            c += cost[tempPath[i]][tempPath[i-1]]; // just take vector<int> pre[MAXV] to vector<int> tempPath
        }
        if(c < minCost){
            minCost = c;
            path = tempPath;
        }
        tempPath.pop_back();
        return;// CRITICAL: not return
    }else{
        tempPath.push_back(v);
        for(int i = 0; i< pre[v].size(); i++){
            DFS(pre[v][i], start);
        }
        tempPath.pop_back();
    }
}

int PATA1030(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &N, &M, &S, &D);
    fill(G[0], G[0]+ MAXV * MAXV, INF);
    for(int i = 0; i < N; i++){ // useless? yes useless, when vis[u] = 1, G[u][u] will not go ahead
        G[i][i] = 0;
    }
    int u,v,dis,c;
    for(int i = 0; i< M; i++){
        scanf("%d%d%d%d", &u, &v, &dis, &c);
        G[u][v] = G[v][u] = dis;
        cost[u][v] = cost[v][u] = c;
    }
    
    int start = S;
    dijkstra(start);
    int end = D;
    DFS(end, start);
    
    // distance
//    int dis = 0;
    for(int i = (int)path.size() -1; i>= 0; i--){
        if(i != (int)path.size()-1)
            printf(" ");
        printf("%d", path[i]);
//        dis += G[path[i]][path[i-1]];
    }
    printf(" %d %d", d[end], minCost);
    
    return 0;
} // AC test case @ 20180305 1802  AC @ 20180309 1913
