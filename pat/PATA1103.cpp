//
//  PATA1103.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// N = n1^p + n2^p + ... + nk^p, N-K-P  // n <= 400, k <= N, 1 < p <= 7

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

static int n, k, p;

static int maxFacSum = -1;
static vector<int> ans, temp, fac;
static int power(int x){
    int ans = 1;
    for(int i = 0; i< p; i++){
        ans *= x;
    }
    return ans;
}
static void init(){
    int i = 0, temp = 0;
    while(temp <= n){
        fac.push_back(temp);
        temp = power(++i);
    }
}
static void DFS(int index, int nowK, int sum, int facSum){
    if(sum == n && nowK == k){
        if(facSum > maxFacSum){
            ans = temp;
            maxFacSum = facSum;
        }
        return;
    }
    if(sum > n || nowK > k )return;
    if(index-1 >= 0){
        temp.push_back(index);
        DFS(index, nowK+1, sum+fac[index], facSum + index);
        temp.pop_back();
        DFS(index-1, nowK, sum, facSum);
    }
}

int PATA1103(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &k, &p);
    init();
//    DFS(n);
    DFS((int)fac.size() -1 , 0, 0, 0);
    if(maxFacSum == -1)printf("Impossible\n");
    else{
        printf("%d = ",n);
        for(int i = 0; i< ans.size(); i++){
            if(i!=0)printf(" + ");
            printf("%d^%d",ans[i], p);
        }
    }
    
    return 0;
}
