//
//  PATA1102.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// input -> tree -> reverse tree -> in order + level order

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 10

static struct Node { // binary is just a structure or a space or a time thing
    int lchild, rchild, value;
}static_binarytree[MAX];

static int N, root_;

static int root_flag_hashTable[MAX] = {0};
//static int find_root(void){
//    int temp;
//
//    return temp;
//}

// ok
//static void post_travel(int root){
//    if(root == -1)
//        return;
//    post_travel(static_binarytree[root].lchild);
//    post_travel(static_binarytree[root].rchild);
//    printf("%d",static_binarytree[root].value);
//}

static void post_travel_reverse(int root){
    if(root == -1)
        return;
    post_travel_reverse(static_binarytree[root].rchild);
    post_travel_reverse(static_binarytree[root].lchild);
    //printf("%d", static_binarytree[root].value); // need
    int temp = static_binarytree[root].rchild;
    static_binarytree[root].rchild = static_binarytree[root].lchild;
    static_binarytree[root].lchild = temp;
}

static int count_travel = 0;
static void in_travel(int root){
    if(root == -1)
        return;
    in_travel(static_binarytree[root].lchild);
    
    if(count_travel != 0)
        printf(" ");
    printf("%d", static_binarytree[root].value);
    count_travel++;
    in_travel(static_binarytree[root].rchild);
}

// todo: implement
static void level_travel(int root){
    if(root == -1)
        return;
    queue<int> q;
    q.push(root);
    int work;
    while(!q.empty()){
        work = q.front();
        if(work != root)
            printf(" ");
        printf("%d", static_binarytree[work].value);
        q.pop();
        if(static_binarytree[work].lchild != -1)
            q.push(static_binarytree[work].lchild);
        if(static_binarytree[work].rchild != -1)
            q.push(static_binarytree[work].rchild);
    }
}

int PATA1102(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    getchar();
    char c;
    for(int i = 0; i < N; i++){
        static_binarytree[i].value = i;
        c = getchar();
        if(c == '-')
            static_binarytree[i].lchild = -1;
        else{
            static_binarytree[i].lchild = c - '0';
            root_flag_hashTable[c-'0'] = 1;
        }
        
        getchar();
        c = getchar();
        if(c == '-')
            static_binarytree[i].rchild = -1;
        else{
            static_binarytree[i].rchild = c - '0';
            root_flag_hashTable[c-'0'] = 1;
        }
        
        getchar();
    }
    
    // find the root of binary tree;
    int root = 0;
    while(root < N && root_flag_hashTable[root] ==1)root++;
    root_ = root;
    
    //post_travel_reverse(root);
    post_travel_reverse(root); // reverse this tree
    level_travel(root);
    printf("\n");
    in_travel(root);
    
    return 0;
} // AC
