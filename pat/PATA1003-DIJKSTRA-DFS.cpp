//
//  PATA1003-DIJKSTRA-DFS.cpp
//  pat
//
//  Created by 帝君 on 2018/3/4.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

const int MAXV = 1000;
const int INF = 1e9;
static int G[MAXV][MAXV], weight[MAXV], n,m,start,dest;

static int paths[MAXV], rescues[MAXV],d[MAXV], vis[MAXV] = {false};
static vector<int> pre[MAXV]; // DIJKSTRA + DFS
static void Dijkstra(int start){
    memset(paths, 0, sizeof(paths));
    memset(rescues, 0, sizeof(rescues)); // MAXV -> sizeof(rescues[])
    fill(d, d+MAXV, INF); // memset(d, d+MAXV, INF) -> fill(d, d+MAXV, INF);
    
    int s = start;
    paths[s] = 1;
    d[s] = 0;
    rescues[s] = weight[s];
    
    for(int i = 0; i< n; i++){
        int u = -1, min = INF;
        for(int j = 0; j< n; j++){
            if(vis[j] == false && d[j] < min){ // critical: vis[j] == false; which belongs to j(or j's condition)
                u = j;
                min = d[u];
            }
        }
        if(u == -1)return;
        vis[u] = 1;
        for(int v = 0; v < n; v++){
            if(vis[v] == false){
                if(G[u][v] != INF){
                    if(d[u] + G[u][v] < d[v]){
                        d[v] = d[u] + G[u][v];
                        rescues[v] = rescues[u] + weight[v];
                        paths[v] = paths[u];
                        pre[v].clear();
                        pre[v].push_back(u);
                    }else if(d[u] + G[u][v] == d[v]){
                        if(rescues[v] < rescues[u] + weight[v]){
                            rescues[v] = rescues[u] + weight[v];
                        }
                        paths[v] += paths[u];
                        pre[v].push_back(u);
                    }
                }
            }
        }
    }
}

static vector<int> path, tempPath;
static int /*cost[MAXV][MAXV], */maxRescues = 0;
static void DFS(int v){
    if(v == start){ // 要在图的层次考虑问题，不要被细节所蒙蔽 // DFS本身也是图的一种结构。
        tempPath.push_back(v);
        int tempRescues = 0;
        for(vector<int>::iterator it = tempPath.begin(); it!=tempPath.end(); it++){
            tempRescues += weight[*it];
        }
        if(tempRescues > maxRescues){
            maxRescues = tempRescues;
            path = tempPath;
        }
        /*
         int tempRecue = 0;
         for(int i = (int)tempPath.size() -1; i> 0; i--){
         int id = tempPath[i], idNext = tempPath[i-1];
         tempRecue += G[id][idNext]; // tempCost += cost[id][idNext];
         }
         if(tempCost < minCost){ //亚历山大的例子和 A1003的emergency的条件是相反的，所以要变化第二条件。不改变minCost的形式，仅用抽象意义替代
         minCost = tempRecue;
         path = tempPath; // vector有助于维持在考虑问题的水平在图上面 // STL(vector)的好处是已知的特性分明的结构和工具
         }
         */
        tempPath.pop_back();
        return;
    }else{
        tempPath.push_back(v);
        for(int i = 0; i< pre[v].size(); i++){
            DFS(pre[v][i]); // 对前驱节点进行DFS// 会偷懒就会抽象。
        }
        tempPath.pop_back();
    }
}

int PATA1003_DIJKSTRA_DFS(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &start, &dest);
    for(int i = 0; i< n; i++){
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(start);
    DFS(dest);
    //    for(int i = (int)path.size() -1; i >= 0; i--){
    //        if(i != (int)path.size() -1)
    //            printf(" ");
    //        printf("%d", path[i]);
    //    }
//    printf("\n");
    printf("%d %d\n", d[dest], maxRescues);
    //    printf("%d %d\n", paths[dest], rescues[dest]);
    return 0;
} // NOT AC @ 20180304 1512
