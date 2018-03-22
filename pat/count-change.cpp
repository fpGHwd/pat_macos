
//
//  count-change.cpp
//  pat
//
//  Created by 帝君 on 2018/3/18.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

static int coins[6] = {0,1,5, 10, 25, 50};

static int cc(int amount, int coc){
    if(amount == 0)
        return 1;
    else if(amount < 0 || coc <= 0){
        return 0;
    }else
        return cc(amount, coc -1) + cc(amount - coins[coc], coc);
}

//static int first_denomination(int koc){
//
//}

int count_change(void){
    
    printf("%d", cc(100, 5));
    
    return 0;
}
