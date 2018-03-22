//
//  DP.cpp
//  pat
//
//  Created by 帝君 on 2018/3/14.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXV 1010

static int fibs[MAXV];
static int fibnacci(int n){
    if(fibs[n] == -1){
        int f;
        if(n == 1 || n == 2){
            f = 1;
        }else{
            f = fibnacci(n-2) + fibnacci(n-1);
        }
        fibs[n] = f;
        return f;
    }else{
        return fibs[n];
    }
}

static int fibnacci_none_dp(int n){
    if(n == 1 || n == 2){
        return 1;
    }else{
        int f = fibnacci_none_dp(n-2) + fibnacci_none_dp(n-1);
        return f;
    }
}

int DP(void){
//    freopen("input.txt", "r", stdin);
    
    fill(fibs, fibs + MAXV, -1);
    time_t tt;
    time(&tt);
    printf("%ld", tt);
    printf("\n%d", fibnacci(100));
    time(&tt);
    printf("\n%ld", tt);
    printf("\n%d", fibnacci_none_dp(44));
    time(&tt);
    printf("\n%ld", tt);
    return 0;
}
