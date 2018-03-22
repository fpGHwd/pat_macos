//
//  pass_ball.cpp
//  pat
//
//  Created by 帝君 on 2018/3/7.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

static const int INF = 1E9;
static int G[5][5];

static void initiate(void){
//    for(int i = 0; i< 5; i++){
//        for(int j = 0; j< 5; j++){
//            if(j == i)
//                G[i][j] = 0;
//            else
//                G[i][j] = INF;
//        }
//    }
    G[0][1] = INF; G[0][2] = 1; G[0][3] = 1; G[0][4] = 1;
    G[1][0] = INF; G[1][2] = 1; G[1][3] = 1; G[1][4] = 1;
    G[2][0] = INF; G[2][1] = INF;G[2][3] = 1; G[2][4] = INF;
    G[3][0] = 1; G[3][1] = 1; G[3][2] = 1; G[3][4] = 1;
    G[4][0] = 1; G[4][1] = 1; G[4][2] = INF; G[4][3] = 1;
}

static void printf_v(void);
static int num = 0;
static vector<int> path;
static void DFS(int u, int n){
    if(n == 5){
        if(u == 0){
            printf_v();
            num++;
        }
        return;
    }else{
        for(auto v = 0; v < 5; v++){
            if(u != v && G[u][v] == 1){
                path.push_back(v);
                DFS(v, n+1);
                path.pop_back();
            }
        }
    }
}

static void printf_v(void){
    if(num != 0)printf("\n");
    for(auto i = 0; i< (int)path.size(); i++){
        printf("%c", 'A' + path[i]);
    }
}

int pass_ball(void){
    initiate();
    path.push_back(0);
    DFS(0, 0);
    return 0;
}
