//
//  disjoint-set.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

#define SET_SIZE 100

static const int N = 5;
static int father[N] = {0};

static void initiate(void){
    for(int i = 0; i <= N; i++){
        father[i] = i;
    }
}

//static int findFather(int x){
//    while(father[x] != x){ // root is the node satisfy: father[node] = node
//        x = father[x];
//    }
//    return x;
//}
//
//static int findFather1(int x){ // find path-expressed
//    int temp = x;
//    while(x!= father[x]){ // find x with the value of this root
//        x = father[x];
//    }
//
//    while(temp != father[temp]){
////        int temp1 = father[temp];
//        int temp1 = temp;
//        father[temp] = x;
//        temp1 = father[temp];
//    }
//    return x;
//}

// To iterate is human; to recurse, divine.
static int findFather(int x){ // find path-expressed with recurrsion
    if(x == father[x])return x;
    else{
        int root = findFather(father[x]);
        father[x] = root;
        return root;
    }
    return x;
}// recurrsion is attractive and satisfy with space entirely

static void Union(int a, int b){
    int fa = findFather(a), fb = findFather(b);
    if(fa!=fb)
        father[fb] = fa;
}

int disjoint_set(void){
    
    return 0;
}
