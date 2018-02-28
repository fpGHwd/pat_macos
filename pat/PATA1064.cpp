//
//  PATA1064.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NODE_VALUE 2000 // not greater than 2000
#define MAX_NUM 1000

static vector<int> seq;
static int CBT[MAX_NUM], N; // quickly build this tree

static int visit_count = 0;
static void inorder_travel(int root){ // root is the place or CBT
    if(root >= N){
        return;
    }else{
        inorder_travel(2*root+1);
        CBT[root] = seq[visit_count++];
        inorder_travel(2*root+2);
    }
}

int PATA1064(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    int node;
    for(int i = 0; i< N; i++){
        scanf("%d", &node);
        seq.push_back(node);
    }
    sort(seq.begin(), seq.end());
    
    int root = 0;
    inorder_travel(root);
    
    for(int i = 0; i< N; i++){
        if(i != 0)
            printf(" ");
        printf("%d", CBT[i]);
    }
    
    return 0;
} // 20180228 1715 //AC
