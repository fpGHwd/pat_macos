
//
//  PATB1032.cpp
//  pat
//
//  Created by 帝君 on 2018/3/16.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static const int maxn = 100010;
static int schools = 0;
static int N, scores[maxn];

int PATB1032(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    int idx, sco;
    for(int i = 1; i<= N; i++){
        scanf("%d%d", &idx, &sco);
        if(idx > schools)schools = idx;
        scores[idx] += sco;
    }
    
    int id = 1;;
    for(int i = 2; i <= schools; i++){
        if(scores[i] > scores[id]){
            id = i;
        }
    }
    
    printf("%d %d", id, scores[id]);
    
    return 0;
}
