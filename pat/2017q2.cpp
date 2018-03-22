//
//  2017q2.cpp
//  pat
//
//  Created by 帝君 on 2018/3/7.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

#define MAX_MONTH 10000

static int rabbits[MAX_MONTH] = {0};

static int months_rabbits(int month){
    for(int i = 1; i<= month; i++){
        for(int j = 0; j < i-3; j++){
            rabbits[i] += rabbits[j];
        }
    }
    
    int sum = 0;
    for(int i =0; i <= month; i++){
        sum+=rabbits[i];
    }
    return sum;
}

int q2_2017(void){
    int m;
    printf("请输入经过的月份数(整形并回车):");
    scanf("%d", &m);
    rabbits[0] = 1;
    
    printf("%d", months_rabbits(m));
    
    return 0;
}
