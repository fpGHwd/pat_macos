//
//  2017q5.cpp
//  pat
//
//  Created by 帝君 on 2018/3/7.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static bool noneDuplicate(int x){
    char c[10];
    int k = 0;
    while(x){
        c[k++] = x%10;
        x = x/10;
    }
    
    for(int i = 0; i< k-1; i++){
        if(c[i] == c[i+1]){
            return true;
        }
    }
    return false;
}

int q5_2017(void){
    int A;
    scanf("%d", &A);
    
    int i = A;
    for(;;i++)
        if(!noneDuplicate(i))
            break;

    printf("%d", i);
    return 0;
}
