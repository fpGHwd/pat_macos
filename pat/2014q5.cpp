//
//  2014q5.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

const int size = 5;
static int G[size][size] = {0};

int q5_2014(void){
    int x = 0, y = size/2;
    for(int i = 1; i <= size * size; i++){
        if(i == 1){
            G[x][y] = i;
        }else{
            if((i-1) % size == 0 && i != 1){
                x = (x+1) % size;
                y = y;
                G[x][y] = i;
            }else{
                x = ((x-1)+size) % size;
                y = (y+1) % size;
                G[x][y] = i;
            }
        }
    }
    
    int c1 = 0;
    for(int i = 0; i < size; i++){
        if(c1 != 0)printf("\n");
        int c2 = 0;
        for(int j = 0; j< size; j++){
            if(c2!=0)printf(" ");
            printf("%2d", G[i][j]);
            c2++;
        }
        c1++;
    }
    
    return 0;
}
