//
//  PATA1066.cpp
//  pat
//
//  Created by 帝君 on 2018/2/28.
//  Copyright © 2018年 Rumi. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;

struct Node{
    struct Node*lchild, *rchild;
    int value,height;
};

static struct Node* newNode(int v){
    struct Node *p = new struct Node;
    p->value = v;
    p->height = 1; // node->height = 0 when node == NULL
    p->lchild = p->rchild = NULL;
    return p;
}

static int heightNode(struct Node *root){
    // root == NULL
    if(root == NULL)return 0;
    return root->height;
}

static void updateHeight(struct Node *root){
    root->height = 1+max(heightNode(root->lchild), heightNode(root->rchild));
}

static int balanceFactor(struct Node *root){
    return (heightNode(root->lchild) - heightNode(root->rchild));
}

static void L(struct Node *&root){
    struct Node *temp_root = root->rchild;
    root->rchild = temp_root->lchild;
    temp_root->lchild = root;
    // update height here
    updateHeight(root);
    updateHeight(temp_root);
    root = temp_root;
}

static void R(struct Node *&root){
    struct Node *temp_root = root->lchild;
    root->lchild = temp_root->rchild;
    temp_root->rchild = root;
    // update height here
    updateHeight(root);
    updateHeight(temp_root);
    root = temp_root;
}

static void insertNode(struct Node *&root, int v){
    if(root == NULL){
        root = newNode(v);
        return;
    }else{
        if(v < root->value){
            insertNode(root->lchild, v); // recursion is proper way
//            heightNode(root);
            updateHeight(root);
            if(balanceFactor(root) == 2){
                if(balanceFactor(root->lchild) == 1){
                    R(root); // R
                }else if(balanceFactor(root->lchild) == -1){
                    // L
                    // R
                    L(root->lchild); // L(root) -> L(root->lchild);
                    R(root);
                }
            }
        }else if(v> root->value){
            insertNode(root->rchild, v);
//            heightNode(root);
            updateHeight(root);
            if(balanceFactor(root) == -2){
                if(balanceFactor(root->rchild) == -1){ //
                    // L
                    L(root);
                }else if(balanceFactor(root->rchild) == 1){ // root->lchild -> root->rchild // finally here AC the sample
                    // R
                    // L
                    R(root->rchild); // R(root); -> R(root->rchild); // here the critical error
                    L(root);
                }
            }
        }else{
            //
        }
    }
}

//static struct Node* create(int data[], int n){
//    struct Node* p = new struct Node;
//    p->lchild = p->rchild = NULL;
//    for(int i = 0; i< n; i++){
//        insertNode(p, data[i]);
//    }
//    return p;
//}

static void createAVL(int data[], int n, struct Node *&root){
    for(int i = 0; i< n; i++){
        insertNode(root, data[i]);
    }
}

#define MAX_N 20
static int input[MAX_N+1];

int PATA1066(void){
    freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d",&input[i]);
    }
    
    struct Node *root = NULL;
    createAVL(input, N, root); // here use struct Node *&root is very proper while return struct Node*
    printf("%d", root->value);
    
    return 0;
} // 20180301 1435 AC the sample // 20180301 1450 AC the sample // 2120 AC
