//
//  minimun-spanning-tree.cpp
//  pat
//
//  Created by 帝君 on 2018/3/4.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

static const int MAXV = 1000;
static const int INF = 1E9;

static int G[MAXV][MAXV], n, m;

static int vis[MAXV], d[MAXV], ans_arc_weight = 0;
static int prim(int start){ // start effects the sequence
    fill(d, d+MAXV, INF );
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <n ; i++){
        G[i][i] = 0;
        d[i] = G[start][i];
    }
    for(int i = 0; i< n; i++){ // from 0 start so the argument is meanless
        int u = -1, min = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == 0 && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1)return -1;
        vis[u] = 1;
        ans_arc_weight += d[u];
        for(int v = 0; v < n; v++){
            if(vis[v] == 0 && G[u][v] != INF && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans_arc_weight;
}

struct Node{
    int u, v, w;
};
static vector<struct Node> arcs;
static int vis_kruskal[MAXV];
static int kruskal(void){ // kruskal only have a sequence when distinct weight
    memset(vis_kruskal, 0, sizeof(vis_kruskal));
    int ans = 0;
    struct Node no;
    for(int i = 0; i < n-1; i++){
        do{
            no = arcs.back();
            arcs.pop_back();
        }while(vis_kruskal[no.u] == 1 && vis_kruskal[no.v] == 1);
        
//        no = arcs.back(); // 明白了
//        while(vis_kruskal[no.u] == 1 && vis_kruskal[no.v] == 1){
//            arcs.pop_back();
//        }
//        arcs.pop_back();
//        if(vis_kruskal[no.u] == 0 || vis_kruskal[no.v] == 0){
        vis_kruskal[no.u] = 1;
        vis_kruskal[no.v] = 1;
        ans += no.w;
            //printf("%d ", no.w);
//        }
    }
    return ans;
}

static int cmp(struct Node a, struct Node b){
    return a.w > b.w;
}

int mst(void){
    freopen("input.txt", "r", stdin);
    fill(G[0], G[0] + MAXV * MAXV,INF);// critical: none this sentence or G[0][0] -> G[0] // add and ok AC the sample
    scanf("%d%d", &n, &m);
    int u, v, w;
    Node no;
    for(int i = 0; i< m; i++){
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = w;
        G[v][u] = w;
        no.u = u;
        no.v = v;
        no.w = w;
        arcs.push_back(no);
    }
    
    sort(arcs.begin(), arcs.end(), cmp);
//    int start = 0;
//    int ans = prim(start);
    int ans = kruskal();
    printf("%d", ans);
    
    return 0;
}

/*
 6 10
 0 1 4
 0 4 1
 0 5 2
 1 2 1
 1 5 3
 2 3 6
 2 5 5
 3 4 5
 3 5 4
 4 5 3
 
 output:
 11
 
 
 6 10
 0 4 1
 0 1 4
 0 5 2
 1 5 3
 1 2 6
 2 5 5
 2 3 6
 3 5 5
 3 4 4
 4 5 3
 
 output
 15
 
 */
