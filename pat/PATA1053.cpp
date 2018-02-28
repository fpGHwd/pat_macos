//
//  PATA1053.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 101
#define MAX_W_ANS 1000
//#define MAX_

static vector<int> tree[MAX_N];
static vector<int> weight; // please not use weight(MACRO_NUM) and weight push_back will get what you do not want

static int path_weight(vector<int> &path){
    int w = 0;
    for(vector<int>::iterator it = path.begin(); it != path.end(); it++){
        w += weight[*it];
    }
    return w;
}

static void print_weight(vector<int> &path){
    for(vector<int>::iterator it = path.begin(); it != path.end(); it++){
        if(it != path.begin())
            printf(" ");
        printf("%d",weight[*it]);
    }
}

static int path_count = 0; // use count will cause confliction // USE path_count to control the format of the output
static void DFS(int root, int depth, vector<int> &path, int ans){ // depth belongs to root, root belongs to tree, and DFS belongs to tree
    if(tree[root].size() == 0){
        path.push_back(root);
        if(path_weight(path) == ans){
            if(path_count != 0)
                printf("\n");
            print_weight(path);
            path_count++;
        }
        path.pop_back();
        return;
    }else{
        path.push_back(root); // forget to add
        for(vector<int>::iterator it = tree[root].begin(); it!= tree[root].end(); it++){
            DFS(*it, depth+1, path, ans);
        }
        path.pop_back(); // forget to add // pop_back method
    }
}

static bool cmp(int a, int b){
    return weight[a] > weight[b];
}

int PATA1053(void){
    freopen("input.txt", "r", stdin);
    int N, M, W;
    scanf("%d%d%d", &N, &M, &W);
    int w;
    for(int i = 0; i< N; i++){
        scanf("%d", &w);
        weight.push_back(w);
    }
    for(int i = 0; i< M; i++){
        int node, num;
        scanf("%d%d", &node, &num);
        int temp;
        for(int j = 0; j < num; j++){
            scanf("%d", &temp);
            tree[node].push_back(temp);
        }
        sort(tree[node].begin(), tree[node].end(), cmp); // sort this non-increasing then AC the sample of test case
    }
    int root = 0, root_depth = 0; // root_depth is useless
    vector<int> path;
    DFS(root, root_depth, path, W);
    
    return 0;
} // TIME transformed to MONEY or REAL // 20180228 1223 but output format didn't match
// 20180228 13:31 AC the sample // AC
