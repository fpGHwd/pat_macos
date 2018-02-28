//
//  PATA1004.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_NUMBER_OF_NODES 110

static vector<int> pedigree_tree[MAX_NUMBER_OF_NODES];
static vector<int> ans[MAX_NUMBER_OF_NODES];
// static int ans = 0;
static int max_depth = 1;
static void DFS(int root, int depth){
    if(pedigree_tree[root].size() == 0){
        ans[depth].push_back(root);
        if(depth +1 > max_depth){
            max_depth = depth + 1;
        }
    }else{
        for(vector<int>::iterator it = pedigree_tree[root].begin(); it != pedigree_tree[root].end(); it++){
            DFS(*it, depth+1);
        }
    }
}

int PATA1004(void){
    freopen("input.txt", "r", stdin);
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i< M; i++){
        int node, num_leaf;
        scanf("%d%d", &node, &num_leaf);
        for(int j = 0; j< num_leaf; j++){
            int leaf;
            scanf("%d", &leaf);
            pedigree_tree[node].push_back(leaf);
        }
    }
    
    int root = 1, root_depth = 0;
    DFS(root, root_depth);

    for(int i = 0; i< max_depth; i++){
        if(i!= 0)
            printf(" ");
        printf("%d", (int)ans[i].size()); // dev may cause problem
    }
    
    
    
    return 0;
} // todo: need rewrite it with BFS route // 20180228 11:25 //AC
