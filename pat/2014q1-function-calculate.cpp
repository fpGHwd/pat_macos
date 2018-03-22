//
//  2014q1-function-calculate.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>

#define E_MACRO 2.718281828
#define PI_MACRO 3.1415926

int function_calculate(){
    double x;
    scanf("%lf", &x);
    double result;
    if(x > 0){
        result = (sqrt(x) + pow(E_MACRO,x)) / (5 * x + 5);
    }else{
        result = ((double)2/3 +  sin((double)60/180 * PI_MACRO)) * abs(x);
    }
    printf("%f", result);
    return 0;
}
