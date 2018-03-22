//
//  20180315anoj02.cpp
//  pat
//
//  Created by 帝君 on 2018/3/15.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static int N, array[10000000];

int ANOJ_201800315_02(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    long long temp;
    int l = 1, r = N, ans = l;
    for(int i = 1; i<=N; i++){
        scanf("%lld" ,&temp);
        if(l < r){ // 找一个没出现的数，然后返回l-1
            if( temp < l || temp > r)r--;
            else if(l == temp)l++;
            else array[temp] = 1;
            while(array[l] && l < r){
                if(array[l]){
                    l++;
                    if(l == r)
                        ans = l-1;
                }
            }
        }else{
            ans = l;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
