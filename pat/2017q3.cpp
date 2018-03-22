//
//  2017q3.cpp
//  pat
//
//  Created by 帝君 on 2018/3/7.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>

using namespace std;

#define MAX (1L<32 -1)

static bool isPrime(int x){
    int sq = (int)sqrt(x);
    if(x == 1)
        return false;
    for(int i = 2; i <= sq; i++){
        if(x%i == 0)
            return false;
    }
    return true;
}

static int primes[10000] = {0};

struct Factor{
    long long p,c;
}factors[10]; // why
static int num = 0;

int q3_2017(void){
    long long n, m;
    scanf("%lld", &n);
    m = n;
    for(int i = 1; i <= (int)sqrt(n); i++){
        if(isPrime(i))
            primes[i] = 1;
    }
    factors[0].p = -1;
    
    int sq = (int)sqrt(n);
    int i = 2;
    for(int i = 2; i<= sq; i++){
        if(isPrime(i)){
            int k = 0;
            while(n%i ==0){
                n = n/i;
                k++;
            }
            if(factors[num-1].p != i && k > 0){
                factors[num].p = i;
                factors[num].c = k;
                num++;
            }
        }
    }
    if( n != 1){ // when 34 or 38 which has a factor bigger than sqrt of them
        factors[num].p = n;
        factors[num].c = 1;
        num++;
    }
    
    printf("%lld=", m);
    for(i =0; i< num; i++){
        for(int j = 0; j< factors[i].c; j++){
            if(!(i == 0 && j == 0))printf("*");
            printf("%lld", factors[i].p);
        }
    }
    
    return 0;
}
