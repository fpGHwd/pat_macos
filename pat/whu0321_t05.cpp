
//
//  whu0321_t05.cpp
//  pat
//
//  Created by 帝君 on 2018/3/21.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

static const int max_n = 210;
static char s1[max_n], s2[max_n];
static vector<int> v1, v2, v3;

static bool is_num(char *s){
    int len = (int)strlen(s);
    for(int i = 0; i< len; i++){
        if(s[i] <'0' || s[i] > '9')
            return false;
    }
    return true;
}

int whu0321_t05(){
    
    freopen("input.txt", "r", stdin);
    gets(s1);
    gets(s2);
    
    if(!(is_num(s1) &&is_num(s2))){
        printf("输入错误");
        return 0; // maybe not right
    }
    
    int len1 = (int)strlen(s1), len2 = (int)strlen(s2);
    int len = (len1 > len2)?len1:len2;
    
    for(int i = len1-1; i >= 0; i--)
        v1.push_back(s1[i]-'0');
    for(int i = len2- 1; i >= 0; i--)
        v2.push_back(s2[i]-'0');
    
    int carry = 0, temp;
    for(int i = 0; i< len; i++){
        temp = carry; // maybe not right
        if(i < len1)temp += v1[i];
        if(i < len2)temp += v2[i];
        v3.push_back(temp%10);
        carry = temp/10;
    }
    if(carry != 0)v3.push_back(carry);
    for(int i = (int)v3.size()-1; i >= 0; i--)printf("%d", v3[i]);
    
    return 0;
} // 20180321 1929
