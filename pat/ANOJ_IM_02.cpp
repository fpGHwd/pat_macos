//
//  ANOJ_IM_02.cpp
//  pat
//
//  Created by 帝君 on 2018/3/12.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>

#define MODE 1000000007

long long Catalan(int n)
{
    if(n <= 1)
        return 1;
    
    long long *h = new long long [n+1]; //保存临时结果
    h[0] = h[1] = 1;        //h(0)和h(1)
    for(int i = 2; i <= n; i++)    //依次计算h(2),h(3)...h(n)
    {
        h[i] = 0;
        for(int j = 0; j < i; j++){ //根据递归式计算 h(i)= h(0)*h(i-1)+h(1)*h(i-2) + ... + h(i-1)h(0)
            h[i] += (h[j] * h[i-1-j])%MODE;
        }
    }
    long long result = h[n]; //保存结果
    delete [] h;       //注意释放空间
    return result;
}

int ANOJ_IM_02(){
    
    int F, N;
    scanf("%d%d", &F, &N);
    if(F == 0){
        printf("%lld", Catalan(N)%MODE);
    }else if(F==1){
        printf("%lld", Catalan(N)%MODE);
    }
    
    return 0;
}
