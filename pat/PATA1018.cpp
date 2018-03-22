//
//  PATA1018.cpp
//  pat
//
//  Created by 帝君 on 2018/3/2.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// graph
const int maxn = 501, INF = 1E9;
static int C,N,S,M, PBMC = 0;
static int G[maxn][maxn], weight[maxn];

// dijkstra
static int vis[maxn] = {0}, d[maxn];
static vector<int> pre[maxn];
static void dijkstra(int start){ // dijkstra degenerate to be a vector<int> pre
    fill(d, d+ maxn, INF);
    d[start] = 0;
    
    for(int i = 0; i< N; i++){
        int u = -1, min = INF;
        for(int j = 0; j< N; j++){
            if(vis[j] == 0 && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1)return;
        vis[u] = 1;
        for(int v = 0; v <= N; v++){ // from 0 to N
            if(vis[v]==0){
                if(G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){ // update d[v]
                        d[v] = d[u] + G[u][v];
                        pre[v].clear();
                        pre[v].push_back(u);
                    }else if(d[u] + G[u][v] == d[v]){
                        pre[v].push_back(u);
                    }
                }
            }
        }
    }
}

// dfs via pre-array
static int minNeed = INF;
static vector<int> tempPath, path;
static void DFS(int v, int start){
    tempPath.push_back(v);
    if(v == start){
        int total = 0, need = 0;
        for(int i = (int)tempPath.size() -1 ; i>= 0; i--){
            total += weight[tempPath[i]];
            if(((int)tempPath.size() - i - 1)*C/2 > total + need)
                need = ((int)tempPath.size() - i - 1)*C/2 - total;
        }
        if(need < minNeed){
            minNeed = need;
            path = tempPath;
        }
    }else
        for(int i = 0; i < pre[v].size(); i++)// has more than one pre node
            DFS(pre[v][i], start);
    tempPath.pop_back();
}

int PATA1018(){
    // read data
    freopen("input.txt", "r", stdin);
    
    // graph
    scanf("%d%d%d%d",&C, &N, &S, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &weight[i]);
    weight[0] = 0;
    int u, v, w;
    fill(G[0], G[0]+ maxn * maxn, INF);
    for(int i = 0; i< M; i++){
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    
    int start = PBMC;
    dijkstra(start);
    int end = S;
    DFS(end, start);

    printf("%d ", minNeed);
    int total = 0;
    for(int i = (int)path.size() -1; i >=0; i--){
        total += weight[path[i]];
        if(i != (int)path.size() -1)
            printf("->");
        printf("%d", path[i]);
    }
    printf(" %d", total + minNeed - C/2 * ((int)path.size() - 1));
    
    /*
    printf("%d 0", minNeed);
    for(int i = (int)path.size() -2; i>= 0; i--)
        printf("->%d", paht[i]);
    printf(" %d", minBack);
    */
     
    return 0;
} // AC test case 201803051645 // only not AC test case 7 @201803111736
