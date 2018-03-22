//
//  2015-q3.cpp
//  pat
//
//  Created by 帝君 on 2018/3/6.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

static int hashT[236] = {0};

static char color[4] = {'R','G','Y'};
static int red_green_yellow[] = {2, 3, 5};
static vector<char> path;
static int num = 0;
static void DFS(int idx){
    if(idx == 8){
        int r = 0,g = 0,y = 0;
        for(int i = (int)path.size() - 1; i>=0; i--){
            switch (path[i]) {
                case 'R':
                    r++;
                    break;
                case 'G':
                    g++;
                    break;
                case 'Y':
                    y++;
                    break;
                default:
                    break;
            }
        }
        if(hashT[r*100 + g * 10 + y] == 0){
            if(num != 0)printf("\n");
            for(int i = (int)path.size() -1; i>=0; i--){
                printf("%c", path[i]);
            }
            hashT[r*100 + g * 10 + y] = 1;
            num++;
        }
        return;
    }else{
        for(int i = 0; i < 3; i++){
            if(red_green_yellow[i] >=1){
                red_green_yellow[i]--;
                path.push_back(color[i]);
                DFS(idx+1);
                path.pop_back();
                red_green_yellow[i]++;
            }
        }
    }
}

int q3_2015(){
    // 要理解不能表述出来的结构和抽象还有空间，真的是靠天赋啊。你把这个程序看做一个空间的结构，拉那里其他的地方就会连一下，要会这样思考。
    DFS(0); // ball you get, path relative
    return 0;
}
