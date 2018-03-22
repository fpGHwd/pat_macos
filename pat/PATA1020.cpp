//
//  PATA1020.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

#define TREE_NODE_MAX 30

static int N;
static int post_order[TREE_NODE_MAX];
static int in_order[TREE_NODE_MAX];


static struct Node{
    struct Node *lchld, *rchld;
    int value;
}*tree;

static Node* create(int post[], int in[], int len){
    if(len == 0)
        return NULL;
    struct Node * pn = new Node;
    pn->value = post[len-1];
    int temp = 0;
    while(in[temp] != pn->value && temp < len)temp++;
    //for(int i = 0; i< len && in[i] != pn->value; i++)temp = i;
    pn->lchld = create(post, in, temp);
    pn->rchld = create(post + temp,in + temp+1, len - temp -1);
    
    return pn;
}

static void level_order(struct Node *root){
    queue <struct Node*> q;
    if(root == NULL)
        return;
    q.push(root);
    struct Node *p;
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p!= tree)
            printf(" ");
        printf("%d", p->value);
        if(p->lchld != NULL)
            q.push(p->lchld);
        if(p->rchld != NULL)
            q.push(p->rchld);
    }
}

int PATA1020(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    
    for(int i = 0; i< N; i++)
        scanf("%d", &post_order[i]);
    for(int i = 0; i< N; i++)
        scanf("%d", &in_order[i]); // solve(get level order) and save to array is a abstractly same process

    tree = create(post_order, in_order, N);
    level_order(tree);
    
    return 0;
} // AC
