//
//  PATB1036.cpp
//  pat
//
//  Created by 帝君 on 2018/3/16.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static int N;
static char C;

int PATB1036(){
    freopen("input.txt", "r", stdin);
    scanf("%d %c", &N, &C);
    int k = N /2 +N %2;
    for(int i = 1; i <= k; i++){
        if(i != 1)printf("\n");
        if(i == 1 || i == k){
            for(int j = 0; j < N; j++){
                printf("%c", C);
            }
        }else{
            printf("%c",C);
            for(int j = 2; j<= N-1;j++){
                printf(" ");
            }
            printf("%c", C);
        }
    }
    
    return 0;
}
