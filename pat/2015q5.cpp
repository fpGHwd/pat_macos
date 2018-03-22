//
//  2015q5.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

int q5_2015(void){
    int a[4];
    scanf("%d.%d.%d.%d", &a[0],&a[1],&a[2],&a[3]);
    for(int i = 0; i< 4; i++){
//        vector<int> temp;
        int k = a[i], temp[8];
        for(int j = 0; j < 8; j++){
            temp[j] = k % 2;
            k = k/2;
        }
        if(i!= 0)printf(".");
        for(int j = 7; j>=0; j--){
            printf("%d", temp[j]);
        }
    }
    
    
    return 0;
}
