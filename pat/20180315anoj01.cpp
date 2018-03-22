//
//  20180315anoj01.cpp
//  pat
//
//  Created by 帝君 on 2018/3/15.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

static const int max_n = 110;
static int N, hashTable[256];
static char s[max_n];

static int kuluo_value(char *s){
    int count_ = 0;
    fill(hashTable, hashTable + max_n, 0);
    int len = (int)strlen(s);
    for(int i = 0; i< len; i++){
        if(isalpha(*(s+i)) && hashTable[*(s+i)] == 0){
            count_++;
            hashTable[*(s+i)] = 1;
        }
    }
    return count_;
}

int ANOJ_201800315_01(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    int sum = 0; // 初值的意义，就是模块的严谨性
    for(int i = 0; i< N; i++){
        scanf("%s", s);
        sum += kuluo_value(s);
    }
    printf("%d", sum);
    return 0;
}
