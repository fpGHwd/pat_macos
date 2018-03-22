//
//  Graph.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;
struct Node{
    int v,w;
    Node(int _v, int _w): v(_v), w(_w){}; // attention
};

#define N 1000
static vector<Node> Adj[N];
static int visited[N] = {0};

static void DFS(int u, int depth){ // visit a node
    visited[u] = 1;
    for(vector<Node>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++){
        if(visited[u] == 0){
            DFS((*it).v, depth+1);
        }
    }
}

static void DFSTravel( int n){ // travel all nodes
    for(int u = 0; u < n; u++){
        if(visited[u]==0){
            DFS(u, 1);
        }
    }
}

int graph_(void){
//    Adj[1].push_back(Node(3,4));
    return 0;
}
