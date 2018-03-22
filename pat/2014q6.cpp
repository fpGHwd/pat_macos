//
//  2014q6.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

// hash to deduplicate path

//#define MAX_NUM  10

static int count_ = 0, threshold = 10; // threshold and count_ is problem or answer relative
static vector<int> v;
void DFS(/*int i,*/ int total_){ // argument is path info, threshold is not path relative, so do not deem threshold as a argument properly
    if(total_ == threshold){ // path info
        if(count_ != 0)printf("\n");
        int num = 0;
        for(int i = 0; i< v.size(); i++){
            if(num!= 0)printf(" ");
            printf("%d",v[i]);
            num++;
        }
        count_++;
        return;
    }else if(total_ < threshold){
        v.push_back(1);
        DFS(total_ + 1);
        v.pop_back();
        v.push_back(2);
        DFS(total_ + 2);
        v.pop_back();
        v.push_back(5);
        DFS(total_ + 5);
        v.pop_back();
    }else{
        return;
    }
}// recursion has arguments always

int details(void){
    DFS(0); // argument is path
    printf("\nTotally has %d methods", count_);
    return 0;
}// 20180306 1159 understanding code == language == space == abstract == relations+is+the+key
