//
//  2017q4.cpp
//  pat
//
//  Created by 帝君 on 2018/3/7.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static const int maxn = 1E9;
static int search_result[maxn], num = 0;

int q4_2017(void){
    int search;
    scanf("%d", &search);
    
    int count_ = 0, temp = 0;
    while(scanf("%d", &temp) != EOF){
        if(search == temp){
            search_result[num++] = count_;
            temp++;
        }
        count_++;
    }
    
    printf("%d", temp);
    for(int i = 0; i< temp; i++){
        printf(" %d", search_result[i]);
    }
    
    return 0;
}
