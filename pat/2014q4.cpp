//
//  2014q4.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <ctype.h> // critical

using namespace std;

#define MAX_LEN 255
static char user_id[MAX_LEN];

static int hashTable[255] = {0}, count_ = 0;

static bool is_valid(char *str){
    if(strlen(user_id) < 10 || !isalpha(user_id[0])){
        return false;
    }else{
        int len = (int)strlen(user_id);
        for(int i = 0; i< len; i++){
            if(user_id[i] == '=' || user_id[i] == '*'){
                return false; // critical
            }else{
                char c = user_id[i];
                if(isdigit(c)){
                    if(hashTable[c] == 0){
                        hashTable[c] = 1;
                        count_++;
                    }
                }
            }
        }
        if( count_ >= 2 && count_ <= 6){
            return true;
        }else{
            return false;
        }
    }
}

int user_id_valid(void){
    scanf("%s", user_id);
    if(!is_valid(user_id))
        printf("Invalid user id");
    else
        printf("Valid user id");
    
    return 0;
}
