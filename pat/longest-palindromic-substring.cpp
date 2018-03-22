//
//  longest-palindromic-substring.cpp
//  pat
//
//  Created by 帝君 on 2018/3/15.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

static const int max_l = 1010;
static char A[max_l];
static int dp[max_l][max_l];

int LPS(void){
    freopen("input.txt", "r", stdin);
    fill(dp[0], dp[0] + max_l * max_l, 0); // dp -> dp[0]
    gets(A+1);
    
    int len = (int)strlen(A+1);
    for(int l = 1; l <= len; l++){
        for(int i = 1; i <= len - l + 1; i++){
            int j = i + l -1;
            if(A[i] == A[j]){
                dp[i][j] = dp[i+1][j-1];
            }else{
                dp[i][j] = 0;
            }
        }
    }
    
    return 0;
}
