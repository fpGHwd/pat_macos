//
//  PATA1086.cpp
//  pat
//
//  Created by 帝君 on 2018/2/27.
//  Copyright © 2018年 Rumi. All rights reserved.
//

// stack -> tree -> post order

#include <cstdio>
#include <stack>
#include <cstring>
#include <stack>
using namespace std;

#define MAX_NODE_NUM 30

static int N;
static int pre_order[30], len_pre = 0;
static int in_order[30], len_in = 0;

struct Node{
    struct Node *lchld, *rchld;
    int value;
};

static Node* create(int pre[], int in[], int len){
    if(len == 0)
        return NULL;
    struct Node * pn = new Node;
    pn->value = pre[0];
    int temp = 0;
    while(in[temp] != pn->value && temp < len)temp++;
    //for(int i = 0; i< len && in[i] != pn->value; i++)temp = i;
    pn->lchld = create(pre+1, in, temp);
    pn->rchld = create(pre + 1 + temp,in + temp + 1, len - (temp+1));
    return pn;
}

static int has_output = 0;
static void post_order(struct Node *root){
    if(root == NULL){
        return;
    }
    post_order(root->lchld);
    post_order(root->rchld);
    if(has_output != 0)
        printf(" ");
    printf("%d", root->value);
    has_output++;
}

int PATA1086(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    getchar();
    char op[5];
    stack <int> s;
    int temp;
    for(int i= 0; i< 2*N; i++){
        scanf("%s", op);
        scanf("%d", &temp);
        if(strcmp(op, "Push") == 0){
            pre_order[len_pre++] = temp;
            s.push(temp);
        }
        else{
            in_order[len_in++] = s.top(); // in_order[len_in++] cannot read accurate value and save
            s.pop();
        }
    }
    
    struct Node *tree = create(pre_order, in_order, len_pre);
    post_order(tree);
    
    return 0;
} // AC
