//
//  2017-hust-q3.cpp
//  pat
//
//  Created by 帝君 on 2018/3/11.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cstring>

#define MAX_LEN 65535

static int hashTable[MAX_LEN]; // 存储余数及其出现位置的hash数组
static int output[MAX_LEN]; // 存储结果
int q3_2018_hust(){
    freopen("input.txt", "r", stdin); // 读文件
    for(int i = 0; i< MAX_LEN; i++) // 初始化hash数组
        hashTable[i] = -1;
    
    int i1, i2;
    scanf("%d/%d", &i1, &i2); // 读取分数
    printf("%d/%d=", i1, i2);
    if(i1 / i2){
        printf("%d", i1/i2); // 如果有整数部分，先打印整数部分
        i1 = i1 % i2;
    }
    printf(".");
    
    int i = 0;
    while(hashTable[i1] == -1){ // 当某次余数在hash数组中有有效的位置，即余数未出现过
        hashTable[i1] = i; // 设置余数的出现的位置i
        output[i] = i1 * 10 /i2; // 计算结果
        i1 = i1 * 10 % i2; // 更新余数
        i++;
    }
    
    for(int j = 0; j < hashTable[i1]; j++){ // 打印小数部分不属于循环部分且在前面的结果
        printf("%d", output[j]);
    }
    
    if(!(hashTable[i1]+1 == i && i1 == 0)){ // 如果循环部分不是有且仅有0，则打印循环部分
        printf("(");
        for(int j = hashTable[i1]; j < i;j++ ) // 从循环开始达到循环结束
            printf("%d", output[j]);
        printf(")");
    }
    
    return 0;
}
