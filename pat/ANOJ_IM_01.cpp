//
//  ANOJ_IM_01.cpp
//  pat
//
//  Created by 帝君 on 2018/3/12.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cmath>

static const double eps = 1e-8;
//#define Equ(a,b) (fabs((a)-(b)) < (eps))
#define More(a,b) (((a) - (b)) > (eps))

int ANOJ_IM_01(){
    freopen("input.txt", "r", stdin);
    
    double a, x, y, b, h;
    scanf("%lf%lf%lf%lf%lf", &a, &x, &y, &b,&h);
    
    double A = (double)(-1)*4 * y / pow(x, 2);
    
    if(A * pow(b-x/2-a, 2) + y > 0){
        if(More(A * pow(b-x/2-a, 2) + y , h)){
            printf("YES");
        }else{
            printf("NO");
        }
    }else{
        printf("YES");
    }
    
    return 0;
}
