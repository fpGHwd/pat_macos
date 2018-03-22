//
//  2015q1.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

int display__(void){
    int n = 0;
    for(int i = 1; i<=8; i++){
        if(n != 0)printf("\n");
        for(int j = 1; j<= i; j++){
            printf("*");
        }
        for(int k = 9 - i; k >= 1; k--){
            printf("%d", k);
        }
        n++;
    }
    
    return 0;
}
