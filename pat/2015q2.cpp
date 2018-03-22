//
//  2015q2.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>

static bool isPrime(int x){
    if(x == 1)
        return false;
    for(int i = 2; i <= (int)sqrt(x); i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

static int fib_seq[31];

int q2_2015(void){
    fib_seq[1] = 1;
    fib_seq[2] = 1;
    int num = 0;
    for(int i = 3; i<= 30; i++){
        fib_seq[i] = fib_seq[i-1]+ fib_seq[i-2];
        if(isPrime(fib_seq[i])){
            if(num != 0)printf(" ");
            printf("%d", fib_seq[i]);
            num++;
        }
    }
    printf("\nTotally has %d primes", num);
    
    return 0;
}
