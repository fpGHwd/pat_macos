//
//  sorta.cpp
//  pat
//
//  Created by 帝君 on 2018/3/5.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 255

struct save{
    char c;
    int count_;
}save_input[MAXN];

static bool cmp(struct save a, struct save b){
    if(a.count_ == b.count_)
        return a.c < b.c;
    else
        return a.count_ > b.count_;
}

int sorta(void){
    char str[100];
    gets(str);
    
    for(int i = 0; i< MAXN; i++){
        save_input[i].c = i;
        save_input[i].count_ = 0;
    }
    
    int len = (int)strlen(str), num = 0;
    for(int i = 0; i < len; i++){
        char c = str[i];
        if(isalpha(c)){
            if(c >= 'A' && c <= 'Z')
                c = c - 'A' + 'a';
            if(save_input[c].count_ == 0)
                num++;
            save_input[c].count_++;
        }
        
    }
    
    sort(save_input, save_input+MAXN, cmp);
    
    for(int i = 0; i< num; i++){
        printf("%c", save_input[i].c);
    }
    return 0;
}
