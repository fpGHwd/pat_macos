//
//  count_tower.cpp
//  pat
//
//  Created by 帝君 on 2018/3/14.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

static const int maxn = 1010;
static int N;
static int states[maxn][maxn],t[maxn * (maxn+1) /2 + 1]; // actually should exchange between states and t in terms of meaning

static int tower(int i, int j){
    if(t[i * (i+1) /2 + j] == -1){
        if(i == N){
            t[i * (i+1) /2 + j] = states[i][j];
            return states[i][j];
        }else{
            return max(tower(i+1, j), tower(i+1, j+1)) + states[i][j];
        }
    }else{
        return t[i * (i+1) /2 + j];
    }
}

int count_tower(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    fill(t, t+maxn * (maxn+1) /2 + 1, -1);
    for(int i = 1; i <= N; i++){
        int v;
        for(int j = 1; j <= i; j++){
            scanf("%d", &v);
            states[i][j] = v;
        }
    }
    
    printf("%d", tower(1,1));
    
    return 0;
}// AC the test case
