//
//  LIS.cpp
//  pat
//
//  Created by 帝君 on 2018/3/14.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// 最长不下降子序列

#include <stdio.h>
#include <algorithm>

using namespace std;

static const int maxn = 1000;
static int dp[maxn], N, A[maxn];

static int dp_(int x){
    if(dp[x] == 1){
        if(x == 0){
            dp[x] = 1;
        }else{
            for(int i = 0; i< N; i++){
                int k = dp_(i);
                if(k + 1 > dp[x] && A[x] > A[i]){
                    dp[x] = k+ 1;
                }
            }
        }
    }
    return dp[x];
}

int LIS(void){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    fill(dp, dp+maxn, 1);
    for(int i= 1; i<= N; i++){
        scanf("%d", &A[i]);
    }
    
    int ans = -1;
    for(int i = 1; i<= N; i++){
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if(dp[j] + 1 > dp[i] && A[i] >= A[j]){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }
    
    printf("%d", ans);
    
    return 0;
}
