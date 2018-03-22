//
//  PATA1003.cpp
//  pat
//
//  Created by 帝君 on 2018/3/2.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

static const int maxn = 500, INF = 1e9; // critical error: 10e9 -> 1e9
static int N, M, C1, C2;
static int G[maxn][maxn], weight[maxn]; // G and rescues have different principle

static int visited[maxn], distances[maxn], w[maxn], path[maxn]; // w[] is essentially the same with d[]
static void Dijkstra(int start){
    fill(distances, distances+maxn, INF); // d initiate to max and d[s] = 0, so put the start into the for(int i = 0; i< N; i++) and get more meaning when coresponding with the former state when the problem is initiated
    memset(path, 0, sizeof(path));
    memset(w, 0, sizeof(w));
    int s = start;
    distances[s] = 0;
    // vis[s] = 1; // critical here: comment and AC the sample
    w[s] = weight[s];
    path[s] = 1;

    for(int i = 0; i< N; i++){ // loop for n times
        int u = -1, min = INF; // -1
        for(int j = 0; j< N; j++){
            if(visited[j] == 0 && distances[j] < min){
                u = j;
                min = distances[j];
            }
        }
        if(u == -1)return;
        visited[u] = 1;
        //w[u] = w[start] + weight[u]; // critical
        //path[u] = 1;
        for(int v = 0; v< N; v++){ // update d[maxn] // there is relative with d, abstract with d
            if(visited[v] == 0){
                if(G[u][v] != INF){
                    if(distances[u] + G[u][v] < distances[v]){
                        distances[v] = distances[u] + G[u][v];
                        w[v] = w[u] + weight[v];
                        path[v] = path[u];
                    }else if(distances[u] + G[u][v] == distances[v]){
                        if(w[u] + weight[v] > w[v]){
                            w[v] = w[u] + weight[v]; // distance
                        }
                        path[v] += path[u]; // distance // path[u] equals to the specific path we has traveled
                    }
                }
            }
        }
    }
}

int PATA1003(){
    freopen("input.txt", "r", stdin); // problem

    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for(int i = 0; i< N; i++){
        scanf("%d", &weight[i]);
    }

    int c1, c2, L;
    fill(G[0], G[0] + maxn * maxn, INF); // G
    for(int i = 0; i< M; i++){
        scanf("%d%d%d", &c1, &c2, &L);
        G[c1][c2] = L;
        G[c2][c1] = L;
    }

    int start = C1, end = C2; // abstract is significant
    Dijkstra(start); // start is part of problem // it's a analogy when you think use a tool and start why is essentially the part of problem.
    printf("%d %d\n", path[end], w[end]); // end is part of problem

    return 0;
} // AC @ 20180304 15:11

/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

output
2 4
 */

//#include <algorithm>
//
//const int MAXV = 510;
//const int INF = 1E9;
//
//static int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
//static int d[MAXV], w[MAXV], num[MAXV];
//static bool vis[MAXV] = {false};
//
//static void Dijkstr(int s){
//    fill(d, d+MAXV, INF);
//    memset(num, 0, sizeof(num));
//    memset(w, 0, sizeof(w));
//    d[s] = 0;
//    w[s] = weight[s];
//    num[s] = 1;
//    for(int i = 0; i< n; i++){
//        int u = -1, min = INF;
//        for(int j = 0; j< n; j++){
//            if(d[i] < min && vis[j] == false){
//                u = j;
//                min  = d[i];
//            }
//        }
//        if(u == -1)return;
//        vis[u] = true;
//        for(int v = 0; v < n; v++){
//            if(G[u][v] != INF){
//                if(vis[v] == false){
//                    if(d[u] + G[u][v] < d[v]){
//                        d[v] = d[u] + G[u][v];
//                        w[v] = w[u] + weight[v];
//                        num[v] = num[u];
//                    }else if(d[u] + G[u][v] == d[v]){
//                        if(w[u] + weight[v] > w[v]){
//                            w[v] = w[u] + weight[v];
//                        }
//                        num[v] += num[u];
//                    }
//                }
//            }
//        }
//    }
//}
//
//int PATA1003(void){
//    freopen("input.txt", "r", stdin);
//    scanf("%d%d%d%d", &n, &m, &st, &ed);
//    for(int i = 0; i< n; i++){
//        scanf("%d", &weight[i]);
//    }
//
//    int u,v;
//    fill(G[0], G[0]+ MAXV * MAXV, INF);
//    for(int i = 0; i < n; i++){
//        scanf("%d%d", &u, &v);
//        scanf("%d", &G[u][v]);
//        G[v][u] = G[u][v];
//    }
//
//    Dijkstr(st);
//    printf("%d %d\n", num[ed], w[ed]);
//
//    return 0;
//}
