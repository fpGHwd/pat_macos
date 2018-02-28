//
//  PATA1106.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_NODES_NUM 100010

static double P, r;
static int n;
static vector<int> tree[MAX_NODES_NUM]; // it's enough to express a tree

static int min_depth = MAX_NODES_NUM, min_depth_count = 0; // needn't a vector<int> to save output info
static void DFS(int root, int depth){ // data[7] error: "1"->"1 8" and pass // depth belongs to root(if it is a structure)
    if(tree[root].size() == 0){
        if(depth == min_depth){
            min_depth_count++;
        }else if(depth < min_depth){
            min_depth_count = 1;
            min_depth = depth;
        }else{
            //
        }
        return;
    }else{
        for(vector<int>::iterator it = tree[root].begin(); it != tree[root].end(); it++){
            DFS(*it, depth+1); // depth belongs to the node *it // depth -> depth + 1, critical
        }
    }
}

int PATA1106(void){
    freopen("input.txt", "r", stdin);
    scanf("%d %lf %lf", &n, &P, &r);
    for(int i = 0; i< n; i++){
        int num, temp;
        scanf("%d", &num);
        for(int j = 0; j< num; j++){
            scanf("%d", &temp);
            tree[i].push_back(temp);
        }
    }
    int root = 0, root_depth = 0;
    DFS(root, root_depth); // root_depth belongs to root
    
    printf("%.4f %d", pow(1+ r * 1.0 / 100, min_depth) * P, min_depth_count); // min_depth_count = 1?
    
    return 0;
} // 20180228 1108 // AC
