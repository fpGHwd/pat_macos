//
//  2014q2-ascii.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

//#define MAX_NUM (1L<<16)
static const int maxn = ((1 << 16)-1);
static char str[maxn];

static int cmp(char a, char b){
    return a < b;
}

int ascii(void){
    scanf("%s", str);
    int len = (int)strlen(str);
    
    sort(str, str + len, cmp);
    printf("%s", str);
    
//    printf("%d", maxn);
    return 0;
}
