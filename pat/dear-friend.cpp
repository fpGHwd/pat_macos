//
//  dearfriend.cpp
//  pat
//
//  Created by 帝君 on 2018/3/1.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

#define MAX_NUM 100+1

static int father[MAX_NUM];
static bool root_flag[MAX_NUM];

static void init(int n){ // initiate the father[i] = i
    for(int i = 1; i<=n; i++){
        father[i] = i;
        root_flag[i] = false;
    }
}

static int findFather(int x){
    if(x == father[x])return x;
    else{
        int root = findFather(father[x]);
        father[x] = root; // every time adjust fathers
        return root;
    }
}

static void Union(int a, int b){
    int af = findFather(a);
    int bf = findFather(b);
    if(af != bf)father[bf] = af; // satisfies math
}

int dearfriend(void){
    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        Union(a,b);
//        if(temp1 > temp2){
//            int temp = temp1;
//            temp1 = temp2;
//            temp2 = temp;
//        }
//        father[temp1] = temp2;
//        father[temp2] = temp2;
    }
    
    for(int i = 1; i<=n; i++){ // when has no friend and not appear in input data
        if(father[i] == -1){
            father[i] = i;
        }
    }
    
    int count_ = 0;
    for(int i = 1; i <= n; i++){
        if(root_flag[father[i]] == 0){
            count_++;
            root_flag[father[i]] = 1;
        }
//        if(father[i] == -1){
//            father[i] = i;
//        }
//        int root = findFather(i); // why root is 0?
//        if(root!= 0 && root_flag[root] == 0){ // when root is invalid
//            count_++;
//            root_flag[root] = 1;
//        }
    }
    
    printf("%d", count_);
    
    return 0;
}
