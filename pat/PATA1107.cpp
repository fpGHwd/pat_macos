//
//  PATA1107.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_N 1001
#define MAX_H 1001
#define MAX_PEOPLE 1010

// father has the information of habits and must save the people index
// but pure disjoint set has no space to save information of these relative habits

static int father[MAX_PEOPLE], N, isRoot[MAX_PEOPLE], courses[MAX_H];

static int findFather(int x){
    if(x == father[x])return x;
    else{
        int f = findFather(father[x]); // int f = findFather(x) -> int f = findFather(father[x]);
        father[x] = f; // path express
        return f;
    }
}

static void Union(int a, int b){ // union
    int af = findFather(a);
    int bf = findFather(b);
    if(af != bf){
        father[bf] = af;
    }
}

static void init_env(void){
    for(int i = 1; i<= N; i++){ // not use 0
        father[i] = i;
        isRoot[i] = 0;
        courses[i] = 0; //
    }
}

static bool cmp(int a, int b){
    return a > b;
}

int PATA1107(void){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    init_env();
    for(int i = 1; i <= N; i++){ // people from 1 ~ N
        int h_num;
        scanf("%d:", &h_num);
        int h_idx;
        for(int j = 0; j< h_num; j++){
            scanf("%d", &h_idx);
            if(courses[h_idx] == 0){
                courses[h_idx] = i; // couses root is i(people) // media
            }else{
                Union(courses[h_idx], i); // union this
            }
        }
    }
    
    for(int i = 1; i<= N; i++)
        isRoot[findFather(i)]++;
    
    int count_ = 0;
    for(int i = 1; i<=N; i++) // count_ is a part of isRoot itself
        if(isRoot[i]!= 0)
            count_++;
    
    sort(isRoot+1, isRoot+N+1, cmp); // people is from 1 to N
    printf("%d\n", count_);
    for(int i = 1; i <=count_; i++){
        if(i != 1)
            printf(" ");
        printf("%d", isRoot[i]);
    }

    return 0;
} // 20180301 1701 AC the sample // 2121 AC
