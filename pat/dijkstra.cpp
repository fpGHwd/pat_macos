//
//  dijkstra.cpp
//  pat
//
//  Created by 帝君 on 2018/3/2.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

// graph
const int INF = 10e9;
static const int maxn = 1010;
static int G[maxn][maxn], N, A;
struct Node{
    int w; // weight of arc
    int v; // arc: adj[u], v
};
static vector<struct Node> adj[maxn];

// dijkstra
static int visited[maxn] = {0}, distances[maxn] = {INF}, pre_nodes[maxn];
static void Dijkstra(int s){
    for(int i = 0; i < N; i++){
        if(i != s)
            distances[i] = G[i][s];
        else
            distances[i] = 0;
    }
    visited[s] = 1;
    
    for(int i = 0; i< N; i++){ // heap optimize O(T) to T(VlgV + E)
        int u = -1, min = INF;
        for(int j = 0; j<N; j++){
            if(visited[j] == 0 && distances[j] < min){
                u = j;
                min = distances[j];
            }
        }
        if(u == -1)return;
        visited[u] = 1;
        for(int v = 0; v< N; v++){
            if(visited[v] == 0){
                if(G[u][v] != INF){
                    if(G[u][v] + distances[u] < distances[v]){
                        distances[v] = G[u][v] + distances[u];
                        pre_nodes[v] = u;
                    }else if(G[u][v] + distances[u] == distances[v] && true){
                        // 第二标尺只会出现在边权相等的情况之下
                    }
                }
            }
        }
    }
}

static int path_count = 0;
static void path(int s, int v){
    if(v == s){
        printf("%d", s);
        path_count++;
        return;
    }
    path(s, pre_nodes[v]);
    printf(" %d",v);
}

int dijkstra(void){
    // graph
    fill(G[0], G[0]+ maxn * maxn, INF);
    freopen("input.txt", "r", stdin);
    int s;
    scanf("%d%d%d", &N, &A, &s);
    int a, b, w;
    for(int i = 0; i< A; i++){
        scanf("%d%d%d", &a, &b, &w);
        G[a][b] = w;
        G[b][a] = w;
    }
    
    // dijkstra from start
    int start = s;
    Dijkstra(start);
    
    // path from start to destination
    int destination = 5;
    printf("\n");
    path(start, destination);
    
    return 0;
}
