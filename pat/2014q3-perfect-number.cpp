//
//  perfect-number.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>

using namespace std;

static bool is_perfect_number(int x){
    int sum = 0;
    for(int i = 1; i <= x/2; i++){
        if(x % i == 0)
            sum += i;
    }
    if(sum == x)
        return true;
    else
        return false;
}

int perfect_num(void){
    int count_ = 0;
    for(int i = 2; i <=1000; i++){
        if(is_perfect_number(i)){
            if(count_!= 0)printf(" ");
            printf("%d", i);
            count_++;
        }
    }
    return 0;
}
