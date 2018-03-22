//
//  greatest-sum-of-subsequence.cpp
//  pat
//
//  Created by 帝君 on 2018/3/14.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXV 1010
static const int INF = -100000;
static int A[MAXV],sum[MAXV], N;

static int dp(int x){
    if(sum[x] == INF){
        if(x == 0)
            sum[x] = A[0];
        else
            sum[x] = max(A[x],dp(x-1) + A[x]);
    }
    return sum[x];
}

int GSS(){
    freopen("input.txt", "r", stdin);
    fill(sum, sum+ MAXV, INF);
    scanf("%d", &N);
    for(int i = 0; i< N; i++){
        scanf("%d", &A[i]);
    }
    
    dp(6);
    int max = sum[0], k = 0;
    for(int i = 1; i< N; i++){
        if(sum[i] > max){
            k = i;
            max = sum[i];
        }
    }
    printf("sum[%d] = %d",k, max);
    return 0;
}
