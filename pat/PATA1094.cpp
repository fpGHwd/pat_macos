//
//  PATA1094.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

#define MAX_MEMBERS 100 // the max number of the node is 99 and the least is 1

static vector<int> tree[MAX_MEMBERS];
static vector<int> num(MAX_MEMBERS+1); // depth numbers
int N, M; // N = number_of_nodes, M = number_of_non_leaf_nodes

static void DFS(int index, int depth){
    num[depth]++;
    if(tree[index].size() == 0){
        return;
    }else{
        for(vector<int>::iterator it = tree[index].begin(); it != tree[index].end(); it++){
            DFS(*it, depth+1); // here is important, not depth++ but depth+1
        }
    }
}

int PATA1094(){
    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i< M; i++){
        int nodes_num, none_leaf_num;
        scanf("%d%d", &nodes_num, &none_leaf_num);
        for(int j = 0; j< none_leaf_num; j++){
            int child;
            scanf("%d", &child);
            tree[nodes_num].push_back(child);
        }
    }
    
    int root = 1; // the root is 1
    DFS(root, 1);
    
    int max_depth = 1;
    for(int i = 2; i < N; i++){
        if(num[i] > num[max_depth]){
            max_depth = i;
        }
    }
    
    printf("%d %d", num[max_depth], max_depth);
    
    return 0;
} // 20180228 1014

// continuous transformation and abstracting benefits, while human is abstraction and abstraction is human.

// AC
