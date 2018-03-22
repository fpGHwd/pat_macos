//
//  longest-common-subsequence.cpp
//  pat
//
//  Created by 帝君 on 2018/3/15.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_S_L 1000
static char M[MAX_S_L], N[MAX_S_L];
static int dp[MAX_S_L][MAX_S_L];

int LCS(){
    freopen("input.txt", "r", stdin);
    gets(M+1);
    gets(N+1);
    
//    fill(dp, dp + MAX_S_L * MAX_S_L, 0);
    
    int lm = (int)strlen(M+1), ln = (int)strlen(N+1);
    for(int i = 1; i<= lm; i++){
        for(int j = 1; j <= ln; j++){
            if(M[i] == N[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    printf("%d", dp[lm][ln]);
    
    return 0;
}
